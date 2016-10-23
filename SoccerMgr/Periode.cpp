#include "Periode.h"

int Periode::get_nb_buts_locale()
{
	return nb_buts_locale;
}

int Periode::get_nb_buts_adverse()
{
	return nb_buts_adverse;
}

Periode::Periode()
{
	duree = 45;
	nb_buts_adverse = 0;
	nb_buts_locale = 0;
}

Periode::Periode(int d, int loc, int adv)
{
	duree = d;
	nb_buts_adverse = adv;
	nb_buts_locale = loc;
}
