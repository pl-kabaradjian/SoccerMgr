#include <vector>
#include <string>
#include "Club.h"

#ifndef _LIGUE_H
#define _LIGUE_H

class Ligue {
	string name;
	vector<Club*> liste_club;

public:
	vector<Club*>* getListeClub();
	void ajouterClub(Club * c);
	Ligue(string name);
};
#endif