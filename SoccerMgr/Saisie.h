#ifndef _SAISIE_H
#define _SAISIE_H

#include <iostream>
#include <string>
#include "enum.h"
#include "Date.h"
#include "Club.h"
#include "Ligue.h"
#include "Joueur_autonome.h"
#include "Joueur_non_autonome.h"

using namespace std;

class Saisie {
public: 
	static int safe_int_cin();
	static string saisie_string();
	static Couleur saisie_couleur();
	static Terrain saisie_terrain();
	static Date saisie_date();
	static Club* choix_club(Ligue* l);
	static Joueur* choix_joueur(Ligue* l);
};
#endif