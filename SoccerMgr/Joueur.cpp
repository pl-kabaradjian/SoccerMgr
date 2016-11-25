#include "Joueur.h"
#include <iostream>

using namespace std;

void Joueur::ajoute_parcours(Parcours * p)
{
	liste_parcours.push_back(p);
}

void Joueur::afficher()
{
	cout << "Nom :" << lastname;
	cout << ", Prenom :" << firstname;
	cout << ", Ville de naissance : " << ville_naissance;
	cout << ", Age : " << age;
	cout << ", Poids : " << poids;
	cout << ", Taille :" << taille;
}

Joueur::Joueur(string nom, string prenom, int age,float t, int p, string vn): Sportif(nom,prenom,age){
	taille = t;
	poids = p;
	ville_naissance = vn;
	contrat = nullptr;
}

Joueur::Joueur()
{
}


bool Joueur::has_contrat()
{
	if (contrat != nullptr) return true;
	else return false;
}

void Joueur::setContrat(Contrat_engagement * c)
{
	contrat = c;
}

string Joueur::getNomPrenom()
{
	return (firstname + " " + lastname);
}

Joueur::~Joueur()
{
	cout << "Joueur detruit" << endl;
}
