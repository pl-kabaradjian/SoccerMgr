#include <limits>
#include <iostream>
#include <string>
#include <map>
#include "saisie.h"
#include "enum.h"
#include "Ligue.h"

//Fonction permettant de faire rentrer un int 
//sans bloquer le programme dans le cas ou une lettre est saisie
int Saisie::safe_int_cin(){
	int res = -1;
	bool is_an_int = false;

	while (!is_an_int)
	{
		if (!(cin >> res)) {
			cout << "Erreur : Chiffres seulement" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			is_an_int = true;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return res;
}

//Fonction permettant de saisir des strings avec des espaces
string Saisie::saisie_string() {
	string s;
	std::getline(std::cin, s);
	return s;
}

//Fonction permettant de faire choisir une couleur a l'utilisateur
Couleur Saisie::saisie_couleur()
{
	std::map<std::string, Couleur> m;
	m["jaune"] = jaune;
	m["rouge"] = rouge;
	m["bleu"] = bleu;
	m["vert"] = vert;
	m["orange"] = orange;
	m["violet"] = violet;
	m["blance"] = blanc;
	m["noir"] = noir;
	m["gris"] = gris;
	m["rose"] = rose;

	bool is_a_color = false;
	std::string s;
	Couleur c = noir;
	while (!is_a_color)
	{
		cin >> s;
		if (m.find(s) == m.end())
		{
			cout << "Erreur : Couleur non disponible." << endl;
		}
		else 
		{
			c = m[s];
			is_a_color = true;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} 
	return c;
}

//Fonction permettant de faire choisir un type de terrain a l'utilisateur
Terrain Saisie::saisie_terrain()
{
	std::map<std::string, Terrain> m;
	m["gazon"] = gazon;
	m["tartan"] = tartan;

	bool is_a_color = false;
	std::string s;
	Terrain t = gazon;
	while (!is_a_color)
	{
		cin >> s;
		if (m.find(s) == m.end())
		{
			cout << "Erreur : Type de terrain non disponible" << endl;
		}
		else
		{
			t = m[s];
			is_a_color = true;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return t;
}

Date Saisie::saisie_date()
{
	int j, m, a;
	cout << ("Annee AAAA ? ") << endl;
	a = safe_int_cin();

	cout << ("Mois MM ? ") << endl;
	m = safe_int_cin();

	cout << ("Jour JJ ? ") << endl;
	j = safe_int_cin();

	return Date(a,m,j);
}

Club * Saisie::choix_club(Ligue * l)
{
	//cout << "Choissisez le club :" << endl << endl;

	//Affichage du choix de club
	if (l->getListeClub()->size() != 0) {
		for (size_t i = 0; i < l->getListeClub()->size(); i++) {
			cout << i + 1 << " : " << *l->getListeClub()->at(i)->getNom() << endl;
		}
	}
	else {
		cout << "Il n'y a pas de clubs dans cette ligue." << endl;
	}
	

	//Recuperation du choix de l'utilisateur
	int reponse = 0;
	bool choix_ok = false;
	do
	{
		reponse = Saisie::safe_int_cin();
		if (reponse < 0 || reponse >(int)l->getListeClub()->size()) {
			cout << "Votre reponse ne correspond pas a un des choix disponibles." << endl;
		}
		else if (reponse > 0) {
			choix_ok = true;
		}
	} while (!choix_ok);
	return l->getListeClub()->at(reponse-1);
}
