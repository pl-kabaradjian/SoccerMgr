#include "Joueur_non_autonome.h"
#include "Date.h"

void Joueur_non_autonome::set_annee_debut(int exp)
{
	experience = exp;
}

int Joueur_non_autonome::getExperience()
{
	return experience;
}

bool Joueur_non_autonome::est_autonome()
{
	return false;
}

Joueur_non_autonome::Joueur_non_autonome(string nom, string prenom, int age, float t, int poids, string vn):Joueur(nom,prenom,age,t,poids,vn)
{
	experience = 0;
}