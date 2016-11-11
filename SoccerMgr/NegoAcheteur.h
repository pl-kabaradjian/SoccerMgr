#ifndef _NEGOACHETEUR_H
#define _NEGOACHETEUR_H
#include "Negociateur.h"
#include "Negociation.h"

class NegoAcheteur : Negociateur{
	friend class Simulation;
	void Negocier();
};
#endif // !_NEGOACHETEUR_H