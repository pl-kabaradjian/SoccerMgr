#include "Titre.h"
#include <iostream>

Titre::~Titre()
{
	cout << "Titre detruit" << endl;
}

Titre::Titre(string n, Date d)
{
	nom_titre = n;
	date_titre = d;
}
