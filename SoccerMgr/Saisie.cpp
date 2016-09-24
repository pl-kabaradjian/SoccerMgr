#include <limits>
#include <iostream>
#include <string>
#include <map>
#include "saisie.h"
#include "enum.h"

int Saisie::safe_int_cin(){
	int res;
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

string Saisie::saisie_string() {
	string s;
	std::getline(std::cin, s);
	return s;
}

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
