#ifndef _EQUIPE_H
#define _EQUIPE_H
#include "Joueur.h"
#include "Club.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Equipe {
    Club * club;
	Joueur * capitaine;
    int nb_joueurs;
    int nb_gardiens;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar << club;
		ar << capitaine;
		ar << nb_joueurs;
		ar << nb_gardiens;
	}
    
public:
	Equipe(Club* c, Joueur* cap, int nb_joueurs, int nb_gardiens);
	Equipe(Club* cl, Joueur* capi);
	Equipe();
};

#endif //_EQUIPE_H