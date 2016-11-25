#ifndef _RESULTAT_H
#define _RESULTAT_H

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Resultat {
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & score_equipe_adverse;
		ar & score_equipe_locale;
	}
	
public: 
	int score_equipe_locale;
	int score_equipe_adverse;
	//void afficher();
	Resultat(int loc, int adv);
	Resultat();
};

#endif //_RESULTAT_H