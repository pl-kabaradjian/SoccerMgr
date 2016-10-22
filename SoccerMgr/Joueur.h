#ifndef _JOUEUR_H
#define _JOUEUR_H

#include "Sportif.h"
#include "Parcours.h"
#include <vector>

class Joueur : public Sportif {
	float taille;
	int poids;
	string ville_naissance;
	vector<Parcours*> liste_parcours;

public :
	void ajoute_parcours(Parcours* p);
	void afficher();
	Joueur(string nom, string prenom, int age, float t, int poids, string vn);
	~Joueur();
};
#endif