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
	Club* club_libere;
	int duree_contrat;
	Date date_debut;
	Reglement reglement;
public:
	Reglement getReglement();
	Contrat_engagement(Joueur* j, Club* c_contractant, Club* c_libere, int duree, Date d_debut, Reglement rglmnt);
};

#endif //_CONTRAT_ENGAGEMENT_H