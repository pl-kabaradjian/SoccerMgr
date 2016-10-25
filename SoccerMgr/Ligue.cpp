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

vector<Joueur*> Ligue::getListeJoueurs()
{
	vector<Joueur*> liste_joueurs;
	Club* curr_club;

	for (size_t i = 0; i < liste_club.size(); i++) {
		curr_club = liste_club.at(i);
		vector<Joueur*>* curr_liste_joueurs = curr_club->getEffectif();

		if (curr_liste_joueurs->size() > 0) {
			for (size_t j = 0; j < curr_liste_joueurs->size(); j++) {
				liste_joueurs.push_back(curr_liste_joueurs->at(j));
			}
		}
	}
	return liste_joueurs;
}

Club * Ligue::getClubJoueur(Joueur* joueur)
{
	Club* reponse = nullptr;
	Club* curr_club;

	for (size_t i = 0; i < liste_club.size(); i++) {
		curr_club = liste_club.at(i);
		vector<Joueur*>* curr_liste_joueurs = curr_club->getEffectif();
		if (curr_liste_joueurs->size() > 0) {
			for (size_t j = 0; j < curr_liste_joueurs->size(); j++) {
				if (curr_liste_joueurs->at(j) == joueur) {
					reponse = curr_club;
				}	
			}
		}
	}

	return reponse;
}
