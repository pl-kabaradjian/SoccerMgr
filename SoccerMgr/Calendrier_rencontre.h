#ifndef _CALENDRIER_RENCONTRE_H
#define _CALENDRIER_RENCONTRE_H

#include <vector>
#include <string>
#include "Rencontre.h"

using namespace std;

class Calendrier_rencontre {
	string nom;
	vector<Rencontre> calendrier;
public:
	void ajouter_rencontre(Rencontre r);
	void afficher_calendrier();
	vector<Rencontre>* get_calendrier();
	Calendrier_rencontre(string n);
};

#endif //_CALENDRIER_RENCONTRE_H