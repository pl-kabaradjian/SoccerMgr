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

	template<typename T> static T safe_number_cin() {
		T res = -1;
		bool is_a_number = false;

		while (!is_a_number)
		{
			if (!(cin >> res)) {
				cout << "erreur : nombre uniquement" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				is_a_number = true;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		return res;
	}
};
#endif