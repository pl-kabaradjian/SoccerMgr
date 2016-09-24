#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Stade.h"
#include "enum.h"
#include "Joueur.h"
#include "Titre.h"
#include "Staff.h"

using namespace std;

#ifndef _CLUB_H
#define _CLUB_H

class Club {
	string nom;
	string Histoire;
	Couleur couleur;
	Date date_creation;
	vector<Joueur*> effectif;
	vector<Titre*> palmares;
	Stade* stade_club;
	string ville;
	string adresse;
	vector<Staff*> staff;

public:
	Club(string n, string hist, Couleur c, Date crea, Stade* s, string v, string adr);
	void ajouter_joueur(Joueur* j);
	void ajouter_titre(Titre* t);
	void ajouter_staff(Staff* s);
	string* getNom();

	~Club();
};
#endif // !_CLUB_H


