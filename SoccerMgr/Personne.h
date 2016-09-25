#include <string>

using namespace std;
#ifndef _PERSONNE_H
#define _PERSONNE_H
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