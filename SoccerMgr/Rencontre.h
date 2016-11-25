#ifndef _RENCONTRE_H
#define _RENCONTRE_H

#include "Match.h"
#include "Date.h"
//#include "Club.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Club;

class Rencontre {
	Date date_rencontre;
	Club * club_local;
	Club * club_adverse;
	Match match_rencontre;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar << date_rencontre;
		ar << club_local;
		ar << club_adverse;
		ar << match_rencontre;
	}

public: 

	string toString();
	Rencontre(Date d, Club* loc, Club* adv, Match m);
	Rencontre(Date d, Club * loc, Club * adv);
	Rencontre();
	void jouer_auto();
	void afficher_resultat();
	bool hasClub(Club* c);
	bool est_terminee();
};

#endif //_RENCONTRE_H