#include "Entraineur.h"
#include <iostream>


Entraineur::Entraineur(string nom, string prenom, int age):Staff(nom,prenom,age,entraineur)
{
	lieu_obtention_grade = "";
}

vector<Titre*>* Entraineur::getPalmares()
{
	return &palmares;
}

void Entraineur::ajouter_titre(Titre* t)
{
	palmares.push_back(t);
}

void Entraineur::afficher()
{
	cout << "Nom :" << lastname;
	cout << ", Prenom :" << firstname;
}

void Entraineur::afficher_palmares() {
	//Affichage de tous les titres presents dans le palmares
	for (size_t i = 0; i < palmares.size(); ++i) {
		palmares.at(i)->afficher();
		cout << endl;
	}
}

string Entraineur::getNomPrenom() {
	return firstname + " " +lastname;
}

Entraineur::~Entraineur()
{
	//cout << "Entraineur detruit" << endl;
}
