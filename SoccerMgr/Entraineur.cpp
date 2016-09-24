#include "Entraineur.h"
#include <iostream>


Entraineur::Entraineur(string nom, string prenom, int age):Staff(nom,prenom,age,entraineur)
{
	lieu_obtention_grade = "";
}

void Entraineur::ajouter_titre(Titre t)
{
	palmares.push_back(t);
}

Entraineur::~Entraineur()
{
	cout << "Entraineur detruit" << endl;
}
