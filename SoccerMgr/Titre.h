#ifndef _TITRE_H
#define _TITRE_H

#include <string>
#include "Date.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;

class Titre {
	string nom_titre;
	Date date_titre;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar << nom_titre;
		ar << date_titre;
	}

public:
	~Titre();
	Titre(string n, Date d);
	void afficher();
};
#endif
