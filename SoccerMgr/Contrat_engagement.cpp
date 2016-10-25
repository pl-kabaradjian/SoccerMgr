#include "Contrat_engagement.h"

Reglement Contrat_engagement::getReglement()
{
	return reglement;
}

Club * Contrat_engagement::getClubLibere()
{
	return club_libere;
}

Contrat_engagement::Contrat_engagement(Joueur * j, Club * c_contractant, Club * c_libere, int duree, Date d_debut, Reglement rglmnt)
{
	joueur_contractant = j;
	club_contractant = c_contractant;
	club_libere = c_libere;
	duree_contrat = duree;
	date_debut = d_debut;
	reglement = rglmnt;
}
