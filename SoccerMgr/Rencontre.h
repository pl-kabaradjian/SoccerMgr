#ifndef _RENCONTRE_H
#define _RENCONTRE_H

#include "Match.h"
#include "Date.h"
//#include "Club.h"

class Club;

class Rencontre {
	Date date_rencontre;
	Club * club_local;
	Club * club_adverse;
	Match match_rencontre;
public: 
	void afficher();
	Rencontre(Date d, Club* loc, Club* adv, Match m);
	Rencontre();
};

#endif //_RENCONTRE_H