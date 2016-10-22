#ifndef _RESULTAT_H
#define _RESULTAT_H

class Resultat {
	int score_equipe_locale;
	int score_equipe_adverse;
public: 
	void afficher();
	Resultat(int loc, int adv);
};

#endif //_RESULTAT_H