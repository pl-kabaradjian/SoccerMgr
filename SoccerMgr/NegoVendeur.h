#ifndef _NEGOVENDEUR_H
#define _NEGOVENDEUR_H
#include "Negociateur.h"
#include "Negociation.h"

class NegoVendeur : Negociateur{
	friend class Simulation;
	void Negocier();
};

#endif // !_NEGOVENDEUR_H