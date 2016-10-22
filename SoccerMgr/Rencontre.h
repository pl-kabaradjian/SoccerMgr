#ifndef _RENCONTRE_H
#define _RENCONTRE_H

#include "Match.h"
#include "Date.h"
class Club;

class Rencontre {
	Date date_rencontre;
	Club* club_local;
	Club* club_adverse;
	Match match;
public: 
	void afficher();
	Rencontre();
};

#endif //_RENCONTRE_H