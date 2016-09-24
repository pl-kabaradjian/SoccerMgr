#include "Personne.h"

#ifndef _STAFF_H
#define _STAFF_H
enum Role {
	president,
	entraineur,
	secretaire,
	recruteur,
};

class Staff : Personne {
	Role role;

public:
	Staff();
	Staff(string nom, string prenom, int age, Role r);
	~Staff();
};
#endif
