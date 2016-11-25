#ifndef _JOUEUR_NON_AUTONOME_H
#define _JOUEUR_NON_AUTONOME_H

#include "Joueur.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>

class Joueur_non_autonome: public Joueur {
	int experience;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & boost::serialization::base_object<Joueur>(*this);
		ar << experience;
	}

public:
	void set_annee_debut(int anne_debut);
	int getExperience();
	virtual bool est_autonome();
	Joueur_non_autonome(string nom, string prenom, int age, float t, int poids, string vn);
	Joueur_non_autonome();
};

#endif //_JOUEUR_NON_AUTONOME_H