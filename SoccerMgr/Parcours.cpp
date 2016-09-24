#include "Parcours.h"
#include <iostream>

Parcours::Parcours(string club, Date d)
{
	nom_club = club;
	date_passage = d;
}

Parcours::~Parcours()
{
	cout << "Parcours detruit" << endl;
}
