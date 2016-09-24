#include "Stade.h"

Stade::Stade(string n = "", int c = 0, string a = "", Terrain t = gazon)
{
	capacity = c;
	nom = n;
	adresse = a;
	terrain = t;
}

Stade::~Stade()
{
	cout << "Stade detruit" << endl;
}
