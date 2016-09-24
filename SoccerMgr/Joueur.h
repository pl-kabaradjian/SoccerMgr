#include "Personne.h"
#include "Parcours.h"
#include <vector>

#ifndef _JOUEUR_H
#define _JOUEUR_H

class Joueur : public Personne {
	float taille;
	float poids;
	string ville_naissance;
	vector<Parcours*> liste_parcours;

public :
	void ajoute_parcours(Parcours* p);
	Joueur(string nom, string prenom, int age, float t, float poids, string vn);
	Joueur();
	~Joueur();
};
#endif