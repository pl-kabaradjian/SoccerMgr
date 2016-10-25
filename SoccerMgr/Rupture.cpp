#include "Rupture.h"

Rupture::Rupture(Joueur * j, Club * c, string r, float penalite)
{
	this->j = j;
	nouveau_club = c;
	raisons = r;
	this->penalite = penalite;
}

Rupture::Rupture()
{
}
