#include "Joueur_non_autonome.h"
#include "Date.h"

void Joueur_non_autonome::set_annee_debut(int anne_debut)
{
	date_anciennete.setYear(anne_debut);
}

int Joueur_non_autonome::get_annees_anciennete()
{
	int anciennete = Date::getDate().getYear() -this->date_anciennete.getYear();
	return anciennete;
}

Joueur_non_autonome::Joueur_non_autonome(string nom, string prenom, int age, float t, int poids, string vn):Joueur(nom,prenom,age,t,poids,vn)
{
	date_anciennete = Date::getDate();
}
