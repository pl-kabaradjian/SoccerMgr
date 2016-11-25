#ifndef _CALENDRIER_RENCONTRE_H
#define _CALENDRIER_RENCONTRE_H

#include <vector>
#include <string>
#include "Rencontre.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

using namespace std;

class Calendrier_rencontre {
	string nom;
	vector<Rencontre*> liste_rencontre;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar << nom;
		ar << liste_rencontre;
	}

public:
	void ajouter_rencontre(Rencontre* r);
	void afficher_calendrier();
	void afficher_rencontre_non_jouee();
	string toString();
	vector<Rencontre*>* get_liste_rencontre();
	vector<Rencontre *> get_liste_rencontre_non_jouees();
	Calendrier_rencontre(string n);
	Calendrier_rencontre();
	string getNom();
	~Calendrier_rencontre();
};

#endif //_CALENDRIER_RENCONTRE_H