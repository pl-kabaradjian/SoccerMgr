#ifndef _CLUB_H
#define _CLUB_H

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Stade.h"
#include "enum.h"
#include "Joueur.h"
#include "Titre.h"
#include "Staff.h"
#include "Entraineur.h"
#include "Contrat_engagement.h"
#include "Rupture.h"

//class Rupture;

using namespace std;

class Rencontre;

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
	Entraineur* trainer;
	vector<Contrat_engagement*> liste_contrats;
	vector<Rupture*> liste_ruptures;

public:
	Club(string n, string hist, Couleur c, Date crea, Stade* s, string v, string adr);
	Club();

	void ajouter_joueur(Joueur* j);
	void ajouter_titre(Titre* t);
	void ajouter_staff(Staff* s);
	void ajouter_entraineur(Entraineur* e);
	void ajouter_contrat(Contrat_engagement* c_r);
	void ajouter_rupture(Rupture* r);
	void supprimer_joueur(Joueur* j);

	void afficher_joueurs();
	void afficher_palmares();
	//void afficher_contrats();

	string* getNom();
	vector<Titre*>* getPalmares();
	Entraineur* getTrainer();
	vector<Rencontre*> getRencontres();
	vector<Joueur*>* getEffectif();
	vector<Contrat_engagement*>* getListe_contrats();

	~Club();
};
#endif // !_CLUB_H


