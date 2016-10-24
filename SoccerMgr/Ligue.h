#ifndef _LIGUE_H
#define _LIGUE_H

#include <vector>
#include <string>
#include "Club.h"
#include "Calendrier_rencontre.h"

class Ligue {
	string name;
	vector<Club*> liste_club;
	vector<Calendrier_rencontre*> liste_calendrier;

public:
	vector<Club*>* getListeClub();
	vector<Calendrier_rencontre*>* getListeCalednrier();
	void ajouterCalendrier(Calendrier_rencontre* c_r);
	void ajouterClub(Club * c);
	Ligue(string name);
};
#endif