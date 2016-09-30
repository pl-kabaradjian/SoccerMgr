#include <iostream>
#include <string>
#include "enum.h"

using namespace std;

#ifndef _SAISIE_H
#define _SAISIE_H

class Saisie {
public: 
	static int safe_int_cin();
	static string saisie_string();
	static Couleur saisie_couleur();
	static Terrain saisie_terrain();
};
#endif