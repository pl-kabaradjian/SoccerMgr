#include "Rencontre.h"

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
