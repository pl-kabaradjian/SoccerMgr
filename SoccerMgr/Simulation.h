#pragma once
#include "NegoAcheteur.h"
#include "NegoVendeur.h"
#include "Negociateur.h"

class Simulation {
	static void lier_negociateurs(NegoAcheteur* a, NegoVendeur* b);
public:
	static void simulerNegociation(NegoAcheteur* n_a, NegoVendeur* n_v);
};