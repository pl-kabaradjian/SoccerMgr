#ifndef _CONTRAT_ENGAGEMENT_H
#define _CONTRAT_ENGAGEMENT_H
#include "Date.h"
#include "Reglement.h"

class Reglement;
class Joueur;
class Club;


class Contrat_engagement {
	Joueur* joueur_contractant;
	Club* club_contractant;
	Club* club_Libere;
	int duree_contrat;
	Date date_debut;
	Reglement reglement;
public:
	Reglement getReglement();
};

#endif //_CONTRAT_ENGAGEMENT_H