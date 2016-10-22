#ifndef _JOUEUR_NON_AUTONOME_H
#define _JOUEUR_NON_AUTONOME_H

#include "Joueur.h"


class Joueur_non_autonome: public Joueur {
	Date date_anciennete;
public: 
	int get_annees_anciennete();
	Joueur_non_autonome();
};

#endif //_JOUEUR_NON_AUTONOME_H