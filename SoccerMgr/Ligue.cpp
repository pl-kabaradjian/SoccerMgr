#include "Ligue.h"

vector<Club*>* Ligue::getListeClub()
{
	return &liste_club;
}

void Ligue::ajouterClub(Club * c)
{
	liste_club.push_back(c);
}

Ligue::Ligue(string name)
{
	this->name = name;
	this->calendrier = Calendrier_rencontre("Calendrier des rencontres");
}
