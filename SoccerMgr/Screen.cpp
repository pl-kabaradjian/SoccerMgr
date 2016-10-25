#include "screen.h"
#include "saisie.h"
#include "Club.h"
#include "enum.h"
#include "Date.h"
#include "Ligue.h"
#include "Entraineur.h"
#include "Joueur.h"
#include "Joueur_autonome.h"
#include "Joueur_non_autonome.h"
#include "Rupture.h"

using namespace std;

//Menu principal
void Screen::menuPrincipal(Ligue* l)
{
	//liste de choix
	string choix1, choix2, choix3, choix0;
	choix1 = "Gestion des clubs";
	choix2 = "Gestion des calendriers";
	choix3 = "Gestion des contrats";
	choix0 = "Quitter le programme";

	//Affichage des choix
	system("CLS");
	cout 
		<< "****************" << endl
		<< "*SOCCER MANAGER*" << endl
		<< "****************" << endl
		<< endl;
	cout << "Vous etes dans le menu principal. Veuillez choisir parmi les choix suivants:" << endl << endl;
	cout << "1 : " << choix1 << endl;
	cout << "2 : " << choix2 << endl;
	cout << "3 : " << choix3 << endl;
	cout << "0 : " << choix0 << endl;
	
	//Recuperation du choix de l'utilisateur
	int reponse = 0;
	bool choix;
	do {
		choix = false;
		cout << endl << "Votre choix ? ";
		reponse = Saisie::safe_int_cin();
		switch(reponse)
		{
		case 1:
			Screen::menuClub(l);
			break;
		case 2:
			Screen::menuCalendrier(l);
			break;
		case 3:
			Screen::menuContrat(l);
			break;
		case 0:
			exit(-1);
			break;
		default:
			cout << "Votre reponse ne correspond pas a un des choix disponibles.";
			reponse = 0;
			choix = true;
			break;
		}
	}
	while (choix);
}

//Menus et sous-menus de gestion de club
void Screen::menuClub(Ligue * l)
{
start:;
	//liste de choix
	string choix1, choix2, choix3, choix4, choix5, choix6;
	choix1 = "Afficher la liste des joueurs";
	choix2 = "Ajouter un club";
	choix3 = "Supprimer un club";
	choix4 = "Afficher l'entraineur avec le plus de titres";
	choix5 = "Afficher le club avec le plus de titres";
	choix6 = "Afficher les rencontres d'un club";

	//Affichage des choix
	system("CLS");
	cout << endl
		 << "*******************"
		 << "*GESTION DES CLUBS*" 
		 << "*******************" << endl
		 << endl 
		 << "Veuillez choisir parmi les choix suivants:" << endl << endl;
	cout << "1 : " << choix1 << endl;
	cout << "2 : " << choix2 << endl;
	cout << "3 : " << choix3 << endl;
	cout << "4 : " << choix4 << endl;
	cout << "5 : " << choix5 << endl;
	cout << "6 : " << choix6 << endl;
	cout << endl << "0 : Retour au menu principal" << endl;

	//Recuperation du choix de l'utilisateur
	int reponse = 0;
	bool choix;
	do {
		choix = false;
		cout << endl << "Votre choix ? ";
		reponse = Saisie::safe_int_cin();
		switch (reponse)
		{
		case 1:
			Screen::menuListeClub(l);
			break;
		case 2:
			Screen::menuCreaClub(l);
			break;
		case 3:
			Screen::menuSupprClub(l);
			break;
		case 4:
			Screen::menuBestTrainer(l);
			break;
		case 5:
			Screen::menuBestclub(l);
			break;
		case 6:
			Screen::menuListeRencontreClub(l);
			break;
		case 0:
			Screen::menuPrincipal(l);
			break;
		default:
			cout << "Votre reponse ne correspond pas a un des choix disponibles.";
			reponse = 0;
			choix = true;
			break;
		}
		goto start;// Screen::menuClub(l);
	} while (choix);
}

void Screen::menuCreaClub(Ligue* l){
	string nom_club, histoire, ville, adresse;
	Couleur c = noir;
	Date d = Date::getDate();
	//liste de choix
	system("CLS");
	cout << "Menu de creation de club: " << endl << endl;
	//nom du club
	cout << "Nom du club ?" << endl;
	nom_club = Saisie::saisie_string();
	//histoire du club
	cout << "Histoire du club ?" << endl;
	histoire = Saisie::saisie_string();
	//Couleur
	cout << "Couleur du club ?" << endl;
	c = Saisie::saisie_couleur();
	//Ville
	cout << "Ville du club ?" << endl;
	ville = Saisie::saisie_string();
	//Adresse
	cout << "Adresse du club ?" << endl;
	adresse = Saisie::saisie_string();
	//Stade
	string nom_stade, adresse_stade;
	Terrain t = gazon;
	int cap;
	////nom du stade
	cout << "Nom du stade ?" << endl;
	nom_stade = Saisie::saisie_string();
	////adresse du stade
	cout << "Adresse du stade ?" << endl;
	adresse_stade = Saisie::saisie_string();
	////terrain
	cout << "Type de terrain ? (gazon ou tartan)" << endl;
	t = Saisie::saisie_terrain();
	////capacite du stade
	cout << "Capacite du stade" << endl;
	cap = Saisie::safe_int_cin();

	//Instanciation des objets
	Stade* s = new Stade(nom_stade, cap, adresse_stade, t);
	l->ajouterClub(new Club(nom_club,histoire,c,d,s,ville,adresse));

	//system("PAUSE");
}

void Screen::menuSupprClub(Ligue* l)
{
	system("CLS");
	cout << "Menu de suppression de club. Choisissez le club que vous souhaitez supprimer: " << endl << endl;
	int reponse = 0;
	
	//Affichage de la liste de choix
	if (l->getListeClub()->size() != 0) {
		for (size_t i = 0; i < l->getListeClub()->size(); i++) {
			cout << i+1 << " : " << *l->getListeClub()->at(i)->getNom() << endl;
		}
	}
	else {
		cout << "Il n'ya pas de clubs dans cette ligue." << endl;
	}
	cout << "0 : Retour au menu de gestion des clubs" << endl;
	cout << endl << "Votre choix: ";// << endl;
	
	//Suppression du club en fonction du choix de l'utilisateur
	bool choix_ok = false;
	do
	{
		reponse = Saisie::safe_int_cin();
		if(reponse < 0 || reponse > (int)l->getListeClub()->size()) {
			cout << "Votre reponse ne correspond pas a un des choix disponibles." << endl;
		}
		else if (reponse > 0) {
			delete(l->getListeClub()->at(reponse - 1));
			l->getListeClub()->erase(l->getListeClub()->begin() + (reponse-1));
			system("PAUSE");
			choix_ok = true;
		}
		else choix_ok = true;
	} while (!choix_ok);
}

void Screen::menuListeClub(Ligue* l) {
	int reponse = 0;

	//Affichage du choix de club
	Screen::affiche_choix_liste_club(l);
	//Recuperation du choix de l'utilisateur
	bool choix_ok = false;
	do
	{
		reponse = Saisie::safe_int_cin();
		if (reponse < 0 || reponse >(int)l->getListeClub()->size()) {
			cout << "Votre reponse ne correspond pas a un des choix disponibles." << endl;
		}
		else if (reponse > 0) {
			system("CLS");

			//Affichage de la liste des joueurs
			cout << "Voici la liste des joueurs du club : " << *l->getListeClub()->at(reponse - 1)->getNom() << endl;
			l->getListeClub()->at(reponse - 1)->afficher_joueurs();
			//Pause de la console pour voir la liste des joueurs
			system("PAUSE");
			//Reaffichage du choix
			Screen::affiche_choix_liste_club(l);
		}
		else
		{
			choix_ok = true;
		}
	} while (!choix_ok);
}

void Screen::menuBestTrainer(Ligue* l)
{
	system("CLS");
	Entraineur* best_trainer;

	if (l->getListeClub()->size() != 0) {
		best_trainer = l->getListeClub()->at(0)->getTrainer();
		//Recherche de l'entraineur ayant le plus de titres
		for (size_t i = 0; i < l->getListeClub()->size(); ++i) {
			size_t tbest = best_trainer->getPalmares()->size();
			size_t tcurrent = tbest;
			if (l->getListeClub()->at(i)->getTrainer() != nullptr) {
				size_t tcurrent = l->getListeClub()->at(i)->getTrainer()->getPalmares()->size();
			}
			if (tcurrent > tbest) {
				best_trainer = l->getListeClub()->at(i)->getTrainer();
			}
		}

		cout << "L'entraineur avec le plus de titres est : " << best_trainer->getNomPrenom() << endl;
		cout << "Liste des titres :" << endl;
		best_trainer->afficher_palmares();
	}
	else
	{
		cout << "Il n'y a pas de clubs dans ligue." << endl << endl;
	}
	system("PAUSE");
}

void Screen::menuBestclub(Ligue* l)
{
	system("CLS");
	Club* best_club;

	if (l->getListeClub()->size() != 0) {
		best_club = l->getListeClub()->at(0);

		//Recherche du club ayant le plus de titres
		for (size_t i = 0; i < l->getListeClub()->size(); ++i) {
			size_t tbest = best_club->getPalmares()->size();
			size_t tcurrent = l->getListeClub()->at(i)->getPalmares()->size();
			if (tcurrent > tbest) {
				best_club = l->getListeClub()->at(i);
			}
		}

		cout << "Le club avec le plus de titres est : " << *best_club->getNom() << endl;
		cout << "Liste des titres :" << endl;
		best_club->afficher_palmares();
	}
	else
	{
		cout << "Il n'y a pas de clubs dans ligue." << endl << endl;
	}
	system("PAUSE");
}

void Screen::affiche_choix_liste_club(Ligue* l) {
	system("CLS");
	cout << "Menu d'affichage des joueurs. Choisissez le club dont vous souhaitez afficher les joueurs: " << endl << endl;

	//Affichage du choix de club
	if (l->getListeClub()->size() != 0) {
		for (size_t i = 0; i < l->getListeClub()->size(); i++) {
			cout << i + 1 << " : " << *l->getListeClub()->at(i)->getNom() << endl;
		}
	}
	else {
		cout << "Il n'y a pas de clubs dans cette ligue." << endl;
	}
	cout << "0 : Retour au menu de gestion des clubs" << endl;
	cout << endl << "Votre choix: ";
}

void Screen::menuListeRencontreClub(Ligue * l)
{
	system("CLS");
	cout << "Veuillez choisir le club dont vous souhaitez afficher les rencontres :" << endl;
	Club* club = Saisie::choix_club(l);
	system("CLS");
	cout << "Liste des rencontre pour le club : " << *club->getNom() << endl << endl;

	for (size_t i = 0; i < l->getListeCalendrier()->size(); i++) {
		Calendrier_rencontre* curr_cal = l->getListeCalendrier()->at(i);
		cout << curr_cal->getNom() << endl;
		if (curr_cal->get_liste_rencontre()->size() > 0) {
			bool cal_has_club = false;
			for (size_t j = 0; j < curr_cal->get_liste_rencontre()->size(); j++) {
				Rencontre* curr_renc = curr_cal->get_liste_rencontre()->at(j);
				if (curr_renc->hasClub(club)) {
					cal_has_club = true;
					cout << "	" << curr_renc->toString() << endl;
				}
			}
			if (!cal_has_club) cout << "le club n'est pas présents dans ce calendrier" << endl;
		}
		else cout << "	" << "Pas de rencontres dans ce calendrier" << endl;
	}
	cout << endl;
	system("PAUSE");
}

//Menus et sous-menus de gestion de calendriers
void Screen::menuCalendrier(Ligue * l)
{
start:;
	//liste de choix
	string choix1, choix2, choix3;
	choix1 = "Afficher la liste des calendriers";
	choix2 = "Creer un calendrier";
	choix3 = "Supprimer un calendrier";

	//Affichage des choix
	system("CLS");
	cout << endl
		<< "*************************"
		<< "*GESTION DES CALENDRIERS*"
		<< "*************************" << endl
		<< endl;
	cout << "Vous etes dans le menu de gestion des calendriers. Veuillez choisir parmi les choix suivants:" << endl << endl;
	cout << "1 : " << choix1 << endl;
	cout << "2 : " << choix2 << endl;
	cout << "3 : " << choix3 << endl;
	cout << endl << "0 : Retour au menu principal" << endl;

	//Recuperation du choix de l'utilisateur
	int reponse = 0;
	bool choix;
	do {
		choix = false;
		cout << endl << "Votre choix ? ";
		reponse = Saisie::safe_int_cin();
		switch (reponse)
		{
		case 1:
			Screen::menuListeCalendrier(l);
			break;
		case 2:
			Screen::menuCreaCalendrier(l);
			break;
		case 3:
			Screen::menuSupprCalendrier(l);
			break;
		case 0:
			Screen::menuPrincipal(l);
			break;
		default:
			cout << "Votre reponse ne correspond pas a un des choix disponibles.";
			reponse = 0;
			choix = true;
			break;
		}
		goto start;// Screen::menuCalendrier(l);
	} while (choix);
}

void Screen::menuCreaCalendrier(Ligue * l)
{
	string nom_calendrier;
	//liste de choix
	system("CLS");
	cout << "Menu de creation de calendrier: " << endl << endl;
	//nom du club
	cout << "Nom du calendrier ?" << endl;
	nom_calendrier = Saisie::saisie_string();

	//Instanciation du calendrier
	l->ajouterCalendrier(new Calendrier_rencontre(nom_calendrier));
}

void Screen::menuListeCalendrier(Ligue * l)
{
start:;
	//Affichage du choix de calendrier
	system("CLS");
	cout << "Menu d'affichage des calendrier. Choisissez le calendrier auquel vous souhaiter acceder : " << endl << endl;

	//Affichage du choix de calendrier
	if (l->getListeCalendrier()->size() > 0) {
		for (size_t i = 0; i < l->getListeCalendrier()->size(); i++) {
			cout << i + 1 << " : " << l->getListeCalendrier()->at(i)->toString() << endl;
		}
	}
	else {
		cout << "Il n'y a pas de calendriers dans cette ligue." << endl;
		system("PAUSE");
		goto end;
	}
	cout << endl << "0 : Retour au menu de gestion des calendriers" << endl;
	cout << endl << "Votre choix: ";

	//recuperation du choix de l'utilisateur
	int reponse = 0;
	bool choix_ok = false;
	do
	{
		reponse = Saisie::safe_int_cin();
		if (reponse < 0 || reponse >(int)l->getListeCalendrier()->size()) {
			cout << "Votre reponse ne correspond pas a un des choix disponibles." << endl;
		}
		else if (reponse > 0) {
			Screen::menuRencontres(l,l->getListeCalendrier()->at(reponse - 1));
			goto start;
		}
		else
		{
			choix_ok = true;
		}
	} while (!choix_ok);
end:;
}

void Screen::menuSupprCalendrier(Ligue * l)
{
	//Affichage du choix de calendrier
	system("CLS");
	cout << "Menu de suppression de calendrier. Choisissez le calendrier que vous souhaiter supprimer : " << endl << endl;

	//Affichage du choix de calendrier
	if (l->getListeCalendrier()->size() > 0) {
		for (size_t i = 0; i < l->getListeCalendrier()->size(); i++) {
			cout << i + 1 << " : " << l->getListeCalendrier()->at(i)->toString() << endl;
		}
	}
	else {
		cout << "Il n'y a pas de calendriers dans cette ligue." << endl;
	}
	cout << endl << "0 : Retour au menu de gestion des clubs" << endl;
	cout << endl << "Votre choix: ";

	//recuperation du choix de l'utilisateur
	int reponse = 0;
	bool choix_ok = false;
	do
	{
		reponse = Saisie::safe_int_cin();
		if (reponse < 0 || reponse >(int)l->getListeCalendrier()->size()) {
			cout << "Votre reponse ne correspond pas a un des choix disponibles." << endl;
		}
		else if (reponse > 0) {
			delete(l->getListeCalendrier()->at(reponse - 1));
			l->getListeCalendrier()->erase(l->getListeCalendrier()->begin() + (reponse - 1));
			system("PAUSE");
			choix_ok = true;
		}
		else break;
	} while (!choix_ok);
}

//Menu et sous-menus de gestion des rencontres
void Screen::menuRencontres(Ligue * l, Calendrier_rencontre * cal)
{
start:;
	//liste de choix
	string choix1, choix2, choix3;
	choix1 = "Afficher la liste des rencontres";
	choix2 = "Ajouter une rencontre";
	choix3 = "Supprimer une rencontre";

	//Affichage des choix
	system("CLS");
	cout << "**********"
		<< cal->getNom()
		 << "**********"
		<<endl << "Veuillez choisir parmi les choix suivants:" << endl << endl;
	cout << "1 : " << choix1 << endl;
	cout << "2 : " << choix2 << endl;
	cout << "3 : " << choix3 << endl;
	cout << endl << "0 : Retour au menu principal" << endl;

	//Recuperation du choix de l'utilisateur
	int reponse = 0;
	bool choix;
	do {
		choix = false;
		cout << endl << "Votre choix ? ";
		reponse = Saisie::safe_int_cin();
		switch (reponse)
		{
		case 1:
			Screen::menuListeRencontres(cal);
			break;
		case 2:
			Screen::menuCreaRencontre(l, cal);
			break;
		case 3:
			//Screen::menuSupprRencontre();
			break;
		case 0:
			goto end;
			break;
		default:
			cout << "Votre reponse ne correspond pas a un des choix disponibles.";
			reponse = 0;
			choix = true;
			break;
		}
		goto start;// Screen::menuRencontres(l, cal);
	} while (choix);
end:;
}

void Screen::menuListeRencontres(Calendrier_rencontre * cal)
{
//start:;
	//Affichage des rencontres
	system("CLS");
	cout << "Menu d'affichage des rencontres. Choisissez la rencontre que vous souhaitez modifer : " << endl << endl;

	//Affichage du choix de calendrier
	if (cal->get_liste_rencontre()->size() > 0) {
		cal->afficher_calendrier();
	}
	else {
		cout << "Il n'y a pas de rencontres dans ce calendrier." << endl;
		system("PAUSE");
		goto end;
	}
	cout << endl << "0 : Retour au menu de gestion des calendriers" << endl;
	cout << endl << "Votre choix: ";

	//recuperation du choix de l'utilisateur
	int reponse = 0;
	bool choix_ok = false;
	do
	{
		reponse = Saisie::safe_int_cin();
		if (reponse < 0 || reponse >(int)cal->get_liste_rencontre()->size()) {
			cout << "Votre reponse ne correspond pas a un des choix disponibles." << endl;
		}
		else if (reponse > 0) {
			//Menu de gestion de rencontre
		}
		else
		{
			choix_ok = true;
		}
	} while (!choix_ok);
end:;
}

void Screen::menuCreaRencontre(Ligue * l, Calendrier_rencontre * cal)
{
	Club* c_loc(0);
	Club* c_adv(0);
	Date d;
	
	//liste des choix
	system("CLS");
	cout << "Menu de creation de rencontre: " << endl << endl;
	//Date de la rencontre
	cout << "Date de la rencontre ?" << endl;
	d = Saisie::saisie_date();
	
	//Choix club local
	system("CLS");
	cout << "Club local ? " << endl;
	c_loc = Saisie::choix_club(l);

	//Choix club adverse
	system("CLS");
	cout << "Club adverse ? " << endl;
	c_adv = Saisie::choix_club(l);

	//system("PAUSE");
	//Instanciation des objets
	cal->ajouter_rencontre(new Rencontre(d, c_loc, c_adv));

	//system("PAUSE");
}

//Menu contrats
void Screen::menuContrat(Ligue * l)
{
start:;
	//liste de choix
	string choix1, choix2, choix3;
	choix1 = "Nouveau transfert";
	//choix2 = "Renouvellement contrat";
	choix3 = "Afficher total encaisse par club";

	//Affichage des choix
	system("CLS");
	cout << endl
		<< "*************************"
		<< "*GESTION DES CONTRATS*"
		<< "*************************" << endl
		<< endl;
	cout << "Vous etes dans le menu de gestion des contrats. Veuillez choisir parmi les choix suivants:" << endl << endl;
	cout << "1 : " << choix1 << endl;
	//cout << "2 : " << choix2 << endl;
	cout << "2 : " << choix3 << endl;
	cout << endl << "0 : Retour au menu principal" << endl;

	//Recuperation du choix de l'utilisateur
	int reponse = 0;
	bool choix;
	do {
		choix = false;
		cout << endl << "Votre choix ? ";
		reponse = Saisie::safe_int_cin();
		switch (reponse)
		{
		case 1:
			Screen::menuTransfert(l);
			break;
		//case 2:
		//	//Screen::menuRenouvellementContrat(l);
		//	break;
		case 2:
			Screen::menuTotauxClub(l);
			break;
		case 0:
			Screen::menuPrincipal(l);
			break;
		default:
			cout << "Votre reponse ne correspond pas a un des choix disponibles.";
			reponse = 0;
			choix = true;
			break;
		}
		goto start;
	} while (choix);
}

void Screen::menuTransfert(Ligue * l)
{
	vector<Joueur*> lst = l->getListeJoueurs();

	system("CLS");
	cout << endl
		<< "*************************"
		<< "*Ajout d'un transfert*"
		<< "*************************" << endl
		<< endl;
	cout << "Veuillez choisir le joueur contractant :" << endl <<
		"Remarque : Un joueur non autonome ne peut pas etre transfere avant 3 ans d'experience " << endl << endl;

	//affichage du joueur
	for (size_t i = 0; i < lst.size(); i++) {
		Joueur* x = lst.at(i);
		Joueur_non_autonome* x_na = (Joueur_non_autonome*)x;
		string c, a;
		if (x->has_contrat()) c = "Oui";
		else c = "Non";
		if (x->est_autonome()) a = "Oui";
		else a = "Non | Experience : " + to_string(x_na->getExperience());
		cout << i + 1 << " : " << x->getNomPrenom() + " | Contrat : " + c + " | Est autonome : " + a << endl;
	}

	//Recuperation choix du joueur
	int reponse = 0;
	bool choix_ok = false;
	do
	{
		reponse = Saisie::safe_int_cin();
		if (reponse <= 0 || reponse >(int)lst.size()) {
			cout << "Votre reponse ne correspond pas a un des choix disponibles." << endl;
		}
		else if (reponse > 0) {
			Joueur* j = lst.at(reponse - 1);
			Joueur_non_autonome* j_a = (Joueur_non_autonome*) j;

			if (j->has_contrat()) {
				if (j->est_autonome()) {
					//cout << "Rupture";//Rupture;
					Screen::menuCreaTransfert(l, j);
				}	
				else if (j_a->getExperience() > 3) {
					cout << "Transfert OK";
					Screen::menuCreaTransfert(l, j);
				}
				else {
					cout << endl << "Transfert impossible : pas assez d'experience" << endl;
					system("PAUSE");
				}
			}
			else {
				Screen::menuCreaTransfert(l, j);
			}
				
			goto end;
		}
		//else if (reponse == 0) goto end;
		else
		{
			choix_ok = true;
		}
	} while (!choix_ok);
end:;
}

void Screen::menuCreaTransfert(Ligue * l, Joueur* j)
{
	system("CLS");
	cout << endl
		<< "*************************"
		<< "*Ajout d'un transfert*"
		<< "*************************" << endl
		<< endl;

	Joueur* joueur_contractant = j;
	cout << "Nouveau club ?" << endl;
	Club* club_contractant = Saisie::choix_club(l);
	Club* club_libere = l->getClubJoueur(j);

	system("CLS");
	cout << endl
		<< "*************************"
		<< "*Ajout d'un transfert*"
		<< "*************************" << endl
		<< endl;

	cout << "Duree du contrat ?" << endl;
	int duree_contrat = Saisie::safe_int_cin();
	cout << "Date de debut ?" << endl;
	Date date_debut = Saisie::saisie_date();

	//Detail du reglement
	system("CLS");
	cout << endl
		<< "*************************"
		<< "*Ajout d'un transfert*"
		<< "*************************" << endl
		<< endl;

	cout << "Seuil du reglement ?" << endl;
	int seuil = Saisie::safe_int_cin();
	cout << "Description des droits du joueur ?" << endl;
	string ddj = Saisie::saisie_string();
	cout << "Montant qui va au club ?" << endl;
	float montant_club = (float)Saisie::safe_int_cin();
	cout << "Montant qui va au joueur ?" << endl;
	float montant_joueur = (float)Saisie::safe_int_cin();

	//Instanciation
	Reglement r(seuil, ddj, montant_club, montant_joueur);
	Contrat_engagement* c_a = new Contrat_engagement(j, club_contractant, club_libere, duree_contrat, date_debut, r);

	if (joueur_contractant->has_contrat() && joueur_contractant->est_autonome()) Screen::menuCreaRupture(l, joueur_contractant, club_contractant, club_libere);
	//Ajout contrat au joueur et au nouveau club
	joueur_contractant->setContrat(c_a);
	club_contractant->ajouter_contrat(c_a);

	//Suppression/Ajout du joueur dans les effectifs de chaque club
	club_contractant->ajouter_joueur(joueur_contractant);
	club_libere->supprimer_joueur(joueur_contractant);

	cout << endl << "Le contrat a ete cree avec succes !" << endl;
	system("PAUSE");
}

void Screen::menuCreaRupture(Ligue * l, Joueur * j, Club * nouv_club, Club* ancien_club)
{
	system("CLS");
	cout << endl
		<< "*************************"
		<< "*Rupture*"
		<< "*************************" << endl
		<< endl;
	cout << "Comme le joueur est autonome et dispose deja d'un contrat : il faut faire une rupture" << endl;
	cout << "Raisons de la rupture ?" << endl;
	string r = Saisie::saisie_string();
	cout << "Montant de la penalite  ?" << endl;
	float p = (float)Saisie::safe_int_cin();

	//ajout de la rupture au club lese
	ancien_club->ajouter_rupture(new Rupture(j, nouv_club, r, p));
}

void Screen::menuTotauxClub(Ligue * l)
{
	int reponse = 0;

	//Choix du club
	system("CLS");
	cout << "Veuillez choisir le club dont vous souhaitez afficher le total des transferts" << endl;
	Club* club = Saisie::choix_club(l);
	
	//Calcul du montant
	vector<Contrat_engagement*> liste_contrats = l->getListeContrats();
	float total = 0.0f;

	for (size_t i = 0; i < liste_contrats.size(); i++) {
		if (liste_contrats.at(i)->getClubLibere() == club) {
			total += liste_contrats.at(i)->getReglement().getMontant();
		}
	}
	system("CLS");
	cout << "Total des transferts encaisses par le club " << *club->getNom() << " : " << total << endl << endl;

	cout << endl;
	system("PAUSE");
}
