#include "Personne.h"
#include <iostream>

Personne::Personne(string ln = "", string fn = "", int a = 0)
//Personne::Personne(string ln, string fn, int a)
{
	lastname = ln;
	firstname = fn;
	if (a > 0) {
		age = a;
	}
	else age = 1;
}

Personne::Personne()
{
	/*lastname = "";
	firstname = "";
	age = 1;*/
}

Personne::~Personne()
{
	//cout << "Peronne detruite" << endl;
}
