#include "Joueur_autonome.h"

//lol

Joueur_autonome::Joueur_autonome(string nom, string prenom, int age, float t, int poids, string vn): Joueur(nom,prenom,age,t,poids,vn)
{
}

Joueur_autonome::Joueur_autonome()
{
}

bool Joueur_autonome::est_autonome()
{
	return true;
}