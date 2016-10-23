#include "Match.h"

Match::Match(Equipe locale, Equipe adverse)
{
	equipe_locale = locale;
	equipe_adverse = adverse;
}

Match::Match()
{
	
}

void Match::ajouter_periode(Periode p)
{
	periodes.push_back(p);
}

void Match::calculer_resultat()
{
	int res_loc = 0;
	int res_adv = 0;
	for (size_t i = 0; i < periodes.size(); i++) {
		res_loc += periodes.at(i).get_nb_buts_locale();
		res_adv += periodes.at(i).get_nb_buts_adverse();
	}
	resultat = Resultat(res_loc, res_adv);
}

Resultat * Match::getResultat()
{
	return &resultat;
}

void Match::jouerMatch()
{
}
