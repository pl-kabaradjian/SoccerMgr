#ifndef _MATCH_H
#define _MATCH_H

#include <vector>
#include "Equipe.h"
#include "Resultat.h"
#include "Periode.h"

using namespace std;

class Match {
	Equipe equipe_locale;
	Equipe equipe_adverse;
	Resultat resultat;
	vector<Periode> periodes;
public: 
	Match(Equipe locale, Equipe adverse);
	Match();

	void ajouter_periode(Periode p);
	void calculer_resultat();
	Resultat* getResultat();
	void afficher_resultat();
	void jouerMatch();
};

#endif //_MATCH_H