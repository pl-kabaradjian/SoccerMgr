#ifndef _CONTRAT_ENGAGEMENT_H
#define _CONTRAT_ENGAGEMENT_H

#include "Date.h"
class Joueur;
class Club;


class Contrat_engagement {
public: 
    Joueur* joueur_contractant;
    Club* club_contractant;
    Club* club_Libere;
    int duree_contrat;
    Date date_debut;
};

#endif //_CONTRAT_ENGAGEMENT_H