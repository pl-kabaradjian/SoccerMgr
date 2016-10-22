#ifndef _PERIODE_H
#define _PERIODE_H

class Periode {
	int duree;
	int nb_buts_locale;
	int nb_buts_adverse;
public: 
	int get_nb_buts_locale();
	int get_nb_buts_adverse();

	Periode();
};

#endif //_PERIODE_H