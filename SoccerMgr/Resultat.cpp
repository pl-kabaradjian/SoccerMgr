#include "Resultat.h"

Resultat::Resultat(int loc, int adv)
{
	score_equipe_adverse = adv;
	score_equipe_locale = loc;
}

Resultat::Resultat()
{
	score_equipe_adverse = -1;
	score_equipe_locale = -1;
}
