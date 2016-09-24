#include <string>
#include "Date.h"

using namespace std;
#ifndef _PARCOURS_H
#define _PARCOURS_H

class Parcours {
	string nom_club;
	Date date_passage;

public:
	Parcours(string club, Date d);
	~Parcours();
};
#endif