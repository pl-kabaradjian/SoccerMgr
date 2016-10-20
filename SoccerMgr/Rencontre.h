#ifndef _RENCONTRE_H
#define _RENCONTRE_H

#include "Match.h"
#include "Date.h"
class Club;

class Rencontre {
public: 
    Date date_rencontre;
    Club* club_local;
    Club* club_adverse;
    Match resultat;
};

#endif //_RENCONTRE_H