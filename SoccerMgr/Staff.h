#ifndef _STAFF_H
#define _STAFF_H

#include "Personne.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>

enum Role {
	president,
	entraineur,
	secretaire,
	recruteur,
};

class Staff :  public virtual Personne {
protected:
	Role role;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & boost::serialization::base_object<Personne>(*this);
		ar << role;
	}

public:
	Staff();
	Staff(string nom, string prenom, int age, Role r);
	Staff(Role r);
	~Staff();
};
#endif
