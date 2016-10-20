#ifndef _PERSONNE_H
#define _PERSONNE_H

#include <string>

using namespace std;

class Personne {
protected:
	string lastname;
	string firstname;
	int age;

public:
	Personne(string ln, string fn, int a);
	Personne();
	~Personne();
};
#endif