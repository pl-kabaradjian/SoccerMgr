#include "Rencontre.h"

string Rencontre::toString()
{
	return date_rencontre.toString() + " " + *club_local->getNom() + " vs " + *club_adverse->getNom();
}

Rencontre::Rencontre(Date d, Club * loc, Club * adv, Match m)
{
	date_rencontre = d;
	club_adverse = adv;
	club_local = loc;
	match_rencontre = m;
}

Rencontre::Rencontre(Date d, Club * loc, Club * adv)
{
	date_rencontre = d;
	club_adverse = adv;
	club_local = loc;
}

Rencontre::Rencontre()
{
}

void Rencontre::jouer_auto()
{
	//creation auto des équipes
	Equipe e_loc, e_adv;
	match_rencontre = Match(e_loc, e_adv);
	match_rencontre.jouerMatch();
}

void Rencontre::afficher_resultat()
{
	int loc = match_rencontre.getResultat()->score_equipe_locale;
	int adv = match_rencontre.getResultat()->score_equipe_adverse;
	string res;
	if (adv > loc) res = *club_adverse->getNom() + " vainqueur";
	else if (loc > adv) res = *club_local->getNom() + " vainqueur";
	else res = "Match nul";

	cout << "Resultat de la rencontre : " << res << endl <<endl;
	cout << "	Club local : " << *club_local->getNom() << " | Score : " << loc;
	cout << "	Club Adverse : " << *club_adverse->getNom() << " | Score : " << adv;
	cout << endl;
}

bool Rencontre::hasClub(Club * c)
{
	if (club_adverse == c || club_local == c) {
		return true;
	}
	else return false;
}

bool Rencontre::est_terminee()
{
	if ((match_rencontre.getResultat()->score_equipe_adverse != -1) || (match_rencontre.getResultat()->score_equipe_locale != -1)) {
		return true;
	}
	else return false;
}
