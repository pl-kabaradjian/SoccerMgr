#ifndef _SPORTIF_H
#define _SPORTIF_H

#include "Personne.h"

class Sportif: public Personne {

public:
	Sportif(string nom, string prenom, int age);
};

#endif //_SPORTIF_H