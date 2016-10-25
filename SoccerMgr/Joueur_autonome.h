#ifndef _JOUEUR_AUTONOME_H
#define _JOUEUR_AUTONOME_H

#include "Joueur.h"

class Joueur_autonome: public Joueur {
public:
	Joueur_autonome(string nom, string prenom, int age, float t, int poids, string vn);
	virtual bool est_autonome();
};

#endif //_JOUEUR_AUTONOME_H