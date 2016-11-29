#ifndef _SPORTIF_H
#define _SPORTIF_H

//#include "Personne.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
//#include <boost/serialization/base_object.hpp>

using namespace std;

class Sportif{
	string sport;
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & sport;
	}

public:
	//Sportif(string nom, string prenom, int age);
	Sportif();
};

#endif //_SPORTIF_H