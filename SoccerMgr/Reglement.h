#ifndef _REGLEMENT_H
#define _REGLEMENT_H

#include <string>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;

class Reglement {
	int seuil;
	string description_droits_joueur;
	float montant_transfert;
	float montant_club;
	float montant_joueur;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & seuil;
		ar & description_droits_joueur;
		ar & montant_transfert;
		ar & montant_club;
		ar & montant_joueur;
	}

public: 
	Reglement(int s, string desc, float m_club, float m_joueur);
	//Reglement(string desc, float m_club, float m_joueur);
	Reglement();
	float getMontant();
};

#endif //_REGLEMENT_H