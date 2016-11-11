#ifndef _NEGOVENDEUR_H
#define _NEGOVENDEUR_H
#include "Negociateur.h"
#include "Negociation.h"

class NegoVendeur : Negociateur, Negociation {
	friend class Simulation;
	void proposerOffre(double montant);
	void rejeterOffre(double montant);
	void accepterOffre(double montant);
	void Negocier();
};

#endif // !_NEGOVENDEUR_H