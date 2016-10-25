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

void Calendrier_rencontre::afficher_rencontre_non_jouee() {
	int cpt = 0;
	vector<Rencontre*> lst_rnj = get_liste_rencontre_non_jouees();
	for (size_t i = 0; i < liste_rencontre.size(); i++) {
		if (!liste_rencontre.at(i)->est_terminee()) {
			cout << cpt + 1 << " : " << liste_rencontre.at(i)->toString() << endl;
			cpt++;
		}	
	}
	if (liste_rencontre.size() == 0) {
		cout << "Toutes le rencntres de ce calendrier ont ete jouees." << endl << endl;
		system("PAUSE");
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

vector<Rencontre*> Calendrier_rencontre::get_liste_rencontre_non_jouees()
{
	vector<Rencontre*> lst_nj;
	for (size_t i = 0; i < liste_rencontre.size(); i++) {
		if (!liste_rencontre.at(i)->est_terminee()) {
			lst_nj.push_back(liste_rencontre.at(i));
		}
	}
	return lst_nj;
}

Calendrier_rencontre::Calendrier_rencontre(string n)
{
	nom = n;
}

Calendrier_rencontre::Calendrier_rencontre()
{
}

string Calendrier_rencontre::getNom()
{
	return nom;
}

Calendrier_rencontre::~Calendrier_rencontre()
{
	cout << "Calendrier detruit" << endl;
}
