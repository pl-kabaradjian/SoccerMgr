#include "Equipe.h"

Equipe::Equipe(Club * c, Joueur * cap, int nb_j, int nb_g)
{
	club = c;
	capitaine = cap;
	nb_joueurs = nb_j;
	nb_gardiens = nb_g;
}

Equipe::Equipe(Club * c, Joueur * cap)
{
	club = c;
	capitaine = cap;
	nb_gardiens = 1;
	nb_joueurs = c->getEffectif()->size();
}

Equipe::Equipe()
{
}
