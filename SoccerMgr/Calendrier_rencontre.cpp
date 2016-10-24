#include "Calendrier_rencontre.h"
#include <string>

void Calendrier_rencontre::ajouter_rencontre(Rencontre* r)
{
	liste_rencontre.push_back(r);
}

void Calendrier_rencontre::afficher_calendrier()
{
	for (size_t i = 0; i < liste_rencontre.size(); i++) {
		cout << i + 1 << " : " << liste_rencontre.at(i)->toString() << endl;
	}
}

string Calendrier_rencontre::toString()
{
	string result = nom + " | Nombre de rencontres : " + to_string((int)liste_rencontre.size());
	return result;
}

vector<Rencontre*>* Calendrier_rencontre::get_liste_rencontre()
{
	return &liste_rencontre;
}

Calendrier_rencontre::Calendrier_rencontre(string n)
{
	nom = n;
}

Calendrier_rencontre::Calendrier_rencontre()
{
}

Calendrier_rencontre::~Calendrier_rencontre()
{
	cout << "Calendrier detruit" << endl;
}
