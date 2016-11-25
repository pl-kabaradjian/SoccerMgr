#ifndef _PARCOURS_H
#define _PARCOURS_H

#include <string>
#include "Date.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;

class Parcours {
	string nom_club;
	Date date_passage;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar << nom_club;
		ar << date_passage;
	}

public:
	Parcours(string club, Date d);
	~Parcours();
};
#endif