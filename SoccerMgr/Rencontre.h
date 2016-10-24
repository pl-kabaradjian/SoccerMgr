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
	string toString();
	Rencontre(Date d, Club* loc, Club* adv, Match m);
	Rencontre(Date d, Club * loc, Club * adv);
	Rencontre();
	bool hasClub(Club* c);
};

#endif //_RENCONTRE_H