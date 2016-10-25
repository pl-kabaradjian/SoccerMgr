#ifndef _RUPTURE_H
#define _RUPTURE_H

#include "Joueur.h"
#include <string>

class Club;

using namespace std;

class Rupture {
	Joueur* j;
	Club* nouveau_club;
	string raisons;
	float penalite;
public:
	Rupture(Joueur* j, Club* c, string r, float penalite);
	Rupture();
};
#endif