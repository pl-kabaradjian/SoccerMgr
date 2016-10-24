#include "Ligue.h"

vector<Club*>* Ligue::getListeClub()
{
	return &liste_club;
}

vector<Calendrier_rencontre*>* Ligue::getListeCalendrier()
{
	return &liste_calendrier;
}

void Ligue::ajouterCalendrier(Calendrier_rencontre * c_r)
{
	liste_calendrier.push_back(c_r);
}

void Ligue::ajouterClub(Club * c)
{
	liste_club.push_back(c);
}

Ligue::Ligue(string name)
{
	this->name = name;
}
