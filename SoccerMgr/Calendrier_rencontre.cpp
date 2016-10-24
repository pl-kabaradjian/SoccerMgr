#include "Calendrier_rencontre.h"
#include <string>

void Calendrier_rencontre::ajouter_rencontre(Rencontre r)
{
	calendrier.push_back(r);
}

void Calendrier_rencontre::afficher_calendrier()
{
}

string Calendrier_rencontre::toString()
{
	string result = nom + " | Nombre de rencontres : " + to_string((int)calendrier.size());
	return result;
}

vector<Rencontre>* Calendrier_rencontre::get_calendrier()
{
	return &calendrier;
}

Calendrier_rencontre::Calendrier_rencontre(string n)
{
	nom = n;
}

Calendrier_rencontre::Calendrier_rencontre()
{
}
