#include "Joueur.h"
#include <iostream>

using namespace std;

void Joueur::ajoute_parcours(Parcours * p)
{
	liste_parcours.push_back(p);
}

Joueur::Joueur(string nom, string prenom, int age,float t, float p, string vn):Personne(nom,prenom,age){
	taille = t;
	poids = poids;
	ville_naissance = vn;
}

Joueur::Joueur()
{
}

Joueur::~Joueur()
{
	cout << "Joueur detruit" << endl;
}
