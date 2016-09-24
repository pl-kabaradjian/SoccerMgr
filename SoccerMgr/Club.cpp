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

string * Club::getNom()
{
	return &nom;
}

Club::~Club()
{
	cout << "Club detruit" << endl;
}
