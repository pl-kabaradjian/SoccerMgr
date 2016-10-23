#include "Calendrier_rencontre.h"

void Calendrier_rencontre::ajouter_rencontre(Rencontre r)
{
	calendrier.push_back(r);
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
