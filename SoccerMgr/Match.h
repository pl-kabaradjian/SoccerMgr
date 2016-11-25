#ifndef _MATCH_H
#define _MATCH_H

#include <vector>
#include "Equipe.h"
#include "Resultat.h"
#include "Periode.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

using namespace std;

class Match {
	Equipe equipe_locale;
	Equipe equipe_adverse;
	Resultat resultat;
	vector<Periode> periodes;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar << equipe_locale;
		ar << equipe_adverse;
		ar << resultat;
		ar << periodes;
	}

public: 
	Match(Equipe locale, Equipe adverse);
	Match();

	void ajouter_periode(Periode p);
	void calculer_resultat();
	Resultat* getResultat();
	void jouerMatch();
};

#endif //_MATCH_H