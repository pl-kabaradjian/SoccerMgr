#include "screen.h"
#include "saisie.h"
#include "Club.h"
#include "enum.h"
#include "Date.h"
#include "Ligue.h"


using namespace std;

void Screen::menuPrincipal(Ligue* l)
{
	//liste de choix
	string choix1, choix2, choix3, choix4, choix0;
	choix1 = "Ajouter un club";
	choix2 = "Supprimer un club";
	choix3 = "Afficher l'entraineur avec le plus de titres";
	choix4 = "Afficher le club avec le plus de titres";
	choix0 = "Quitter le programme";

	//Affichage des choix
	system("CLS");
	cout << "Vous etes dans le menu principal. Veuillez choisir parmi les choix suivants:" << endl;
	cout << "1 : " << choix1 << endl;
	cout << "2 : " << choix2 << endl;
	cout << "3 : " << choix3 << endl;
	cout << "4 : " << choix4 << endl;
	cout << "0 : " << choix0 << endl;

	string* stringChoix(0);
	
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
			Screen::menuBestTrainer(l);
			break;
		case 4:
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
	cout << "Menu de creation de club: " << endl;
	//nom du club
	cout << "Nom du club ?" << endl;
	nom_club = Saisie::saisie_string();
	//histoire du club
	cout << "Histoire du club ?" << endl;
	histoire = Saisie::saisie_string();
	//Couleur
	cout << "Couleur du club ?" << endl;
	c = Saisie::saisie_couleur();
	////Date (auto ?)
	//d = Date::getDate();
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
	cout << "Menu de suppression de club. Choisissez le club que vous souhaitez supprimer: " << endl;
	int reponse = 0;
	//bool choix;

	cout << "Nombre de clubs : " << l->getListeClub()->size() << endl;
	
	if (l->getListeClub()->size() != 0) {
		for (int i = 0; i < l->getListeClub()->size(); i++) {
			cout << i+1 << " : " << *l->getListeClub()->at(i)->getNom() << endl;
		}
	}
	else {
		cout << "Il n'ya pas de clubs dans cette ligue." << endl;
	}

	cout << "0 : Retour au menu principal" << endl;

	cout << "Votre choix: " << endl;
	cin >> reponse;

	if (reponse = 0) {

	}

	//system("PAUSE");
}

void Screen::menuBestTrainer(Ligue* l)
{
	system("CLS");
	cout << "Meilleur entraineur: " << endl;
	system("PAUSE");
}

void Screen::menuBestclub(Ligue* l)
{
	system("CLS");
	cout << "Meilleur club: " << endl;
	system("PAUSE");
}