#ifndef _LIGUE_H
#define _LIGUE_H

#include <vector>
#include <string>
#include "Club.h"
#include "Calendrier_rencontre.h"

class Ligue {
	string name;
	vector<Club*> liste_club;
	Calendrier_rencontre calendrier;

public:
	vector<Club*>* getListeClub();
	void ajouterClub(Club * c);
	Ligue(string name);
};
#endif