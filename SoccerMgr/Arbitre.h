#ifndef _ARBITRE_H
#define _ARBITRE_H

#include "Sportif.h"

class Arbitre: public Sportif {
	int experience;
public: 
    string lieu_obtention_diplome;
	void add_experience(int i);
	void add_experience();
};

#endif //_ARBITRE_H