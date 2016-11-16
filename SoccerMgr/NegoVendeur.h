#ifndef _NEGOVENDEUR_H
#define _NEGOVENDEUR_H
#include "Negociateur.h"
#include "Negociation.h"

class NegoVendeur : Negociateur{
	double montant_min;
	friend class Simulation;
	void Negocier(bool* deal);
public:
	NegoVendeur(double m_s, Club* c, double min);
};

#endif // !_NEGOVENDEUR_H