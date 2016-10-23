#ifndef _EQUIPE_H
#define _EQUIPE_H
#include "Joueur.h"
#include "Club.h"

class Equipe {
    Club * club;
	Joueur * capitaine;
    int nb_joueurs;
    int nb_gardiens;
    
public:
	Equipe(Club* c, Joueur* cap, int nb_joueurs, int nb_gardiens);
	Equipe(Club* cl, Joueur* capi);
	Equipe();
};

#endif //_EQUIPE_H