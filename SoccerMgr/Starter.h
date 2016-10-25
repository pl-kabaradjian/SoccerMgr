#ifndef _Starter_H
#define _Starter_H

#include "Club.h"
#include "Ligue.h"
#include "Stade.h"
#include "Date.h"
#include "Joueur_autonome.h"
#include "Joueur_non_autonome.h"

class Starter {
public:
	static void load(Ligue* l);
};
#endif