#ifndef _NEGOACHETEUR_H
#define _NEGOACHETEUR_H
#include "Negociateur.h"
#include "Negociation.h"

class NegoAcheteur : Negociateur, Negociation {
	friend class Simulation;
	void proposerOffre(double montant);
	void rejeterOffre(double montant);
	void accepterOffre(double montant);
	void Negocier();
};
#endif // !_NEGOACHETEUR_H