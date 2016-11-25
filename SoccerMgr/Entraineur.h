#ifndef _ENTRAINEUR_H
#define _ENTRAINEUR_H

#include "Staff.h"
#include "Sportif.h"
#include <vector>
#include "Titre.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/vector.hpp>

class Entraineur : public Staff, public Sportif {
	string lieu_obtention_grade;
	vector<Titre*> palmares;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & boost::serialization::base_object<Staff>(*this);
		ar & boost::serialization::base_object<Sportif>(*this);
		ar & lieu_obtention_grade;
		ar & palmares;
	}

public:
	Entraineur(string nom, string prenom, int age);
	Entraineur() {};
	vector<Titre*>* getPalmares();
	void ajouter_titre(Titre* t);
	void afficher();
	void afficher_palmares();
	string getNomPrenom();
	~Entraineur();
};
#endif