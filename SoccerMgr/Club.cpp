#include "Club.h"

Club::Club(string n, string hist, Couleur c, Date crea, Stade* s, string v, string adr)
{
	nom = n;
	Histoire = hist;
	couleur = c;
	date_creation = crea;
	stade_club = s;
	ville = v;
	adresse = adr;
}

Club::Club() {

}

void Club::ajouter_joueur(Joueur * j)
{
	effectif.push_back(j);
}

void Club::ajouter_titre(Titre * t)
{
	palmares.push_back(t);
}

void Club::ajouter_staff(Staff * s)
{
	staff.push_back(s);
}

void Club::ajouter_entraineur(Entraineur* e)
{
	trainer = e;
}

void Club::afficher_joueurs()
{
	//Affichage de tous les joueurs presents dans l'effectif
	for (size_t i = 0; i < effectif.size(); ++i) {
		effectif.at(i)->afficher();
		cout << endl;
	}
}

void Club::afficher_palmares()
{
	//Affichage de tous les titres presents dans le palmares
	for (size_t i = 0; i < palmares.size(); ++i) {
		palmares.at(i)->afficher();
		cout << endl;
	}
}

string * Club::getNom()
{
	return &nom;
}

vector<Titre*>* Club::getPalmares()
{
	return &palmares;
}

Entraineur * Club::getTrainer()
{
	return trainer;
}

void Club::ajouter_contrat(Contrat_engagement c_r)
{
	liste_contrats.push_back(c_r);
}

Club::~Club()
{
	cout << "Club detruit" << endl;
}
