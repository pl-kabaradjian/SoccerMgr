#include <string>
#include "Date.h"

#ifndef _TITRE_H
#define _TITRE_H

using namespace std;

class Titre {
	string nom_titre;
	Date date_titre;

public:
	~Titre();
	Titre(string n, Date d);
	void afficher();
};
#endif
