#ifndef _PERIODE_H
#define _PERIODE_H

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Periode {
	int duree;
	int nb_buts_locale;
	int nb_buts_adverse;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar << duree;
		ar << nb_buts_locale;
		ar << nb_buts_adverse;
	}

public: 
	int get_nb_buts_locale();
	int get_nb_buts_adverse();

	Periode();
	Periode(int d, int loc, int adv);
};

#endif //_PERIODE_H