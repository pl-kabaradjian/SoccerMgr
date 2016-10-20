#ifndef _STADE_H
#define _STADE_H

#include <string>
#include <iostream>
#include "enum.h"

using namespace std;

class Stade {
	int capacity;
	string nom;
	string adresse;
	Terrain terrain;

public:
	Stade(string n, int c, string a, Terrain t);
	~Stade();
};
#endif