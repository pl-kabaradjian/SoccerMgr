#ifndef _LIGUE_H
#define _LIGUE_H

#include <vector>
#include <string>
#include "Club.h"
#include "Calendrier_rencontre.h"
#include "Joueur.h"
#include "Contrat_engagement.h"
//#include "boost_export.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

class Ligue {
	string name;
	vector<Club*> liste_club;
	vector<Calendrier_rencontre*> liste_calendrier;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & name;
		ar & liste_club;
		ar & liste_calendrier;
	}

public:
	vector<Club*>* getListeClub();
	vector<Calendrier_rencontre*>* getListeCalendrier();
	void ajouterCalendrier(Calendrier_rencontre* c_r);
	void ajouterClub(Club * c);
	Ligue(string name);
	vector<Joueur*> getListeJoueurs();
	vector<Contrat_engagement*> getListeContrats();
	Club* getClubJoueur(Joueur* j);
	void run();

	bool b_exit;
};
#endif