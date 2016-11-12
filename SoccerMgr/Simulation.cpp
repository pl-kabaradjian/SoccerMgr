#include "Simulation.h"
#include <thread>

void Simulation::lier_negociateurs(NegoAcheteur* a, NegoVendeur* b)
{
	a->envoi = b->reception;
	b->envoi = a->reception;
}

void Simulation::simulerNegociation(NegoAcheteur* n_a, NegoVendeur* n_v)
{
	//lier les negociateurs
	Simulation::lier_negociateurs(n_a, n_v);

	//creation des threads


	std::thread t_acheteur(&NegoAcheteur::Negocier, n_a);
	std::thread t_vendeur(&NegoVendeur::Negocier, n_v);
	t_acheteur.join();
	t_vendeur.join();
}
