#ifndef _CONTRAT_ENGAGEMENT_H
#define _CONTRAT_ENGAGEMENT_H
#include "Date.h"
#include "Reglement.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Joueur;
class Club;


class Contrat_engagement {
	Joueur* joueur_contractant;
	Club* club_contractant;
	Club* club_libere;
	int duree_contrat;
	Date date_debut;
	Reglement reglement;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & joueur_contractant;
		ar & club_contractant;
		ar & club_libere;
		ar & duree_contrat;
		ar & date_debut;
		ar & reglement;
	}

public:
	Reglement getReglement();
	Club* getClubLibere();
	Contrat_engagement(Joueur* j, Club* c_contractant, Club* c_libere, int duree, Date d_debut, Reglement rglmnt);
	Contrat_engagement() {};
};

#endif //_CONTRAT_ENGAGEMENT_H