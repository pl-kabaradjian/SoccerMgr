#ifndef _JOUEUR_H
#define _JOUEUR_H

#include "Sportif.h"
#include "Parcours.h"
#include "Contrat_engagement.h"
#include <vector>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/vector.hpp>

class Joueur : public Sportif {
	float taille;
	int poids;
	string ville_naissance;
	vector<Parcours*> liste_parcours;
	Contrat_engagement* contrat;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & boost::serialization::base_object<Sportif>(*this);
		ar << taille;
		ar << poids;
		ar << ville_naissance;
		ar << liste_parcours;
		ar << contrat;
	}

public :
	void ajoute_parcours(Parcours* p);
	void afficher();
	virtual bool est_autonome() = 0;
	bool has_contrat();
	void setContrat(Contrat_engagement* c);
	string getNomPrenom();

	Joueur(string nom, string prenom, int age, float t, int poids, string vn);
	Joueur();
	~Joueur();
};
#endif