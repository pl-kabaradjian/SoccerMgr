#ifndef _JOUEUR_AUTONOME_H
#define _JOUEUR_AUTONOME_H

#include "Joueur.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>

class Joueur_autonome: public Joueur {

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & boost::serialization::base_object<Joueur>(*this);
	}

public:
	Joueur_autonome(string nom, string prenom, int age, float t, int poids, string vn);
	Joueur_autonome();
	virtual bool est_autonome();
};
#endif //_JOUEUR_AUTONOME_H