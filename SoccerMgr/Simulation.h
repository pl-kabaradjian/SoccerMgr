#pragma once
#include "NegoAcheteur.h"
#include "NegoVendeur.h"
#include "Negociateur.h"

struct result_simu {
	bool deal;
	double montant;
	result_simu(bool b, double d) {
		deal = b;
		montant = d;
	}
};

class Simulation {
	static void lier_negociateurs(NegoAcheteur* a, NegoVendeur* b);
public:
	static result_simu simulerNegociation(NegoAcheteur* n_a, NegoVendeur* n_v);
};

