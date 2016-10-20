#ifndef _EQUIPE_H
#define _EQUIPE_H

class Joueur;
class Club;

class Equipe {
public: 
    Club* Club;
    int nb_joueurs;
    int nb_gardiens;
    Joueur* capitaine;
};

#endif //_EQUIPE_H