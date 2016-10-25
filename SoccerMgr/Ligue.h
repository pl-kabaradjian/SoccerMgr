#ifndef _LIGUE_H
#define _LIGUE_H

#include <vector>
#include <string>
#include "Club.h"
#include "Calendrier_rencontre.h"
#include "Joueur.h"

class Ligue {
	string name;
	vector<Club*> liste_club;
	vector<Calendrier_rencontre*> liste_calendrier;

public:
	vector<Club*>* getListeClub();
	vector<Calendrier_rencontre*>* getListeCalendrier();
	void ajouterCalendrier(Calendrier_rencontre* c_r);
	void ajouterClub(Club * c);
	Ligue(string name);
	vector<Joueur*> getListeJoueurs();
	Club* getClubJoueur(Joueur* j);
};
#endif