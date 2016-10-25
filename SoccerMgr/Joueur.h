#ifndef _JOUEUR_H
#define _JOUEUR_H

#include "Sportif.h"
#include "Parcours.h"
#include "Contrat_engagement.h"
#include <vector>

class Joueur : public Sportif {
	float taille;
	int poids;
	string ville_naissance;
	vector<Parcours*> liste_parcours;
	Contrat_engagement* contrat;

public :
	void ajoute_parcours(Parcours* p);
	void afficher();
	Joueur(string nom, string prenom, int age, float t, int poids, string vn);
	virtual bool est_autonome() = 0;
	bool has_contrat();
	void setContrat(Contrat_engagement* c);
	string getNomPrenom();
	~Joueur();
};
#endif