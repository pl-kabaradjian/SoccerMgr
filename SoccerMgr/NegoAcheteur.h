#ifndef _NEGOACHETEUR_H
#define _NEGOACHETEUR_H
#include "Negociateur.h"
#include "Negociation.h"

class NegoAcheteur : Negociateur{
	double montant_max;
	friend class Simulation;
	void Negocier(bool* deal);
public:
	NegoAcheteur(double m_s, Club* c, double max);
};
#endif // !_NEGOACHETEUR_H