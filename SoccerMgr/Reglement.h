#ifndef _REGLEMENT_H
#define _REGLEMENT_H

#include <string>

using namespace std;

class Reglement {
	int seuil;
	string description_droits_joueur;
	float montant_transfert;
	float montant_club;
	float montant_joueur;
public: 
	Reglement();
};

#endif //_REGLEMENT_H