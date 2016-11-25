#ifndef _STADE_H
#define _STADE_H

#include <string>
#include <iostream>
#include "enum.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

using namespace std;

class Stade {
	int capacity;
	string nom;
	string adresse;
	Terrain terrain;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & capacity;
		ar & nom;
		ar & adresse;
		ar & terrain;
	}

public:
	Stade(string n, int c, string a, Terrain t);
	Stade() {};
	~Stade();
};
#endif