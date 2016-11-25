#ifndef _RUPTURE_H
#define _RUPTURE_H

#include "Joueur.h"
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Club;

using namespace std;

class Rupture {
	Joueur* j;
	Club* nouveau_club;
	string raisons;
	float penalite;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & j;
		ar & nouveau_club;
		ar & raisons;
		ar & penalite;
	}

public:
	Rupture(Joueur* j, Club* c, string r, float penalite);
	Rupture();
};
#endif