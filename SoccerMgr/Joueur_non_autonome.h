#ifndef _JOUEUR_NON_AUTONOME_H
#define _JOUEUR_NON_AUTONOME_H

#include "Joueur.h"


class Joueur_non_autonome: public Joueur {
	int experience;
public:
	void set_annee_debut(int anne_debut);
	int getExperience();
	virtual bool est_autonome();
	Joueur_non_autonome(string nom, string prenom, int age, float t, int poids, string vn);
};

#endif //_JOUEUR_NON_AUTONOME_H