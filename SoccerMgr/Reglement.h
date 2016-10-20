#ifndef _REGLEMENT_H
#define _REGLEMENT_H

#include <string>

using namespace std;

class Reglement {
public: 
    int seuil;
    string description_droits_joueur;
    float montant_transfert;
    float montant_club;
    float montant_joueur;
};

#endif //_REGLEMENT_H