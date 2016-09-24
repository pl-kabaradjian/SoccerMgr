#include "Staff.h"
#include <vector>
#include "Titre.h"

#ifndef _ENTRAINEUR_H
#define _ENTRAINEUR_H

class Entraineur : Staff {
	string lieu_obtention_grade;
	vector<Titre> palmares;

public:
	Entraineur(string nom, string prenom, int age);
	void ajouter_titre(Titre t);
	~Entraineur();
};
#endif