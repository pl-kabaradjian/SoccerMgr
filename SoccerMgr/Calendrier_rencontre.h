#ifndef _CALENDRIER_RENCONTRE_H
#define _CALENDRIER_RENCONTRE_H

#include <vector>
#include <string>
#include "Rencontre.h"

using namespace std;

class Calendrier_rencontre {
	string nom;
	vector<Rencontre*> liste_rencontre;
public:
	void ajouter_rencontre(Rencontre* r);
	void afficher_calendrier();
	string toString();
	vector<Rencontre*>* get_liste_rencontre();
	Calendrier_rencontre(string n);
	Calendrier_rencontre();
	string getNom();
	~Calendrier_rencontre();
};

#endif //_CALENDRIER_RENCONTRE_H