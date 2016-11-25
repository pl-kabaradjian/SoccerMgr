#ifndef _PERSONNE_H
#define _PERSONNE_H

#include <string>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;

class Personne {
protected:
	string lastname;
	string firstname;
	int age;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & lastname;
		ar & firstname;
		ar & age;
	}

public:
	Personne(string ln, string fn, int a);
	Personne();
	~Personne();
};
#endif