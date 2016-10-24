#include "screen.h"
#include "saisie.h"
#include "Club.h"
#include "enum.h"
#include "Date.h"
#include "Ligue.h"
#include "Entraineur.h"


using namespace std;

void Screen::menuPrincipal(Ligue* l)
{
	//liste de choix
	string choix1, choix2, choix3, choix4, choix5, choix0;
	choix1 = "Ajouter un club";
	choix2 = "Supprimer un club";
	choix3 = "Afficher la liste des joueurs";
	choix4 = "Afficher l'entraineur avec le plus de titres";
	choix5 = "Afficher le club avec le plus de titres";
	choix0 = "Quitter le programme";

	//Affichage des choix
	system("CLS");
	cout << "Vous etes dans le menu principal. Veuillez choisir parmi les choix suivants:" << endl << endl;
	cout << "1 : " << choix1 << endl;
	cout << "2 : " << choix2 << endl;
	cout << "3 : " << choix3 << endl;
	cout << "4 : " << choix4 << endl;
	cout << "5 : " << choix5 << endl;
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
			Screen::menuCreaClub(l);
			break;
		case 2:
			Screen::menuSupprClub(l);
			break;
		case 3:
			Screen::menuListeClub(l);
			break;
		case 4:
			Screen::menuBestTrainer(l);
			break;
		case 5:
			Screen::menuBestclub(l);
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
	cout << "0 : Retour au menu principal" << endl;
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
			size_t tcurrent = l->getListeClub()->at(i)->getTrainer()->getPalmares()->size();
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
		cout << "Il n'ya pas de clubs dans cette ligue." << endl;
	}
	cout << "0 : Retour au menu principal" << endl;
	cout << endl << "Votre choix: ";
}

