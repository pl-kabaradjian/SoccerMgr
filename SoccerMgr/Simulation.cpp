#include "Simulation.h"
#include <thread>

void Simulation::lier_negociateurs(NegoAcheteur* a, NegoVendeur* b)
{
	a->envoi = b->reception;
	b->envoi = a->reception;
}

bool Simulation::simulerNegociation(NegoAcheteur* n_a, NegoVendeur* n_v)
{
	//lier les negociateurs
	Simulation::lier_negociateurs(n_a, n_v);

	//creation des threads
	bool deal = false;
	std::thread t_acheteur(&NegoAcheteur::Negocier, n_a,&deal);
	std::thread t_vendeur(&NegoVendeur::Negocier, n_v,&deal);
	t_acheteur.join();
	t_vendeur.join();

	return deal;
}
