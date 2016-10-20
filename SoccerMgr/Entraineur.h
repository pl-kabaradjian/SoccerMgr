#ifndef _ENTRAINEUR_H
#define _ENTRAINEUR_H

#include "Staff.h"
#include <vector>
#include "Titre.h"

class Entraineur : public Staff {
	string lieu_obtention_grade;
	vector<Titre*> palmares;

public:
	Entraineur(string nom, string prenom, int age);
	vector<Titre*>* getPalmares();
	void ajouter_titre(Titre* t);
	void afficher();
	void afficher_palmares();
	string getNomPrenom();
	~Entraineur();
};
#endif