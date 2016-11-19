#include "Simulation.h"
#include <thread>

void Simulation::lier_negociateurs(NegoAcheteur* a, NegoVendeur* b)
{
	queue<Message>* q1 = new queue<Message>;
	queue<Message>* q2 = new queue<Message>;
	a->envoi = q1;
	b->reception = q1;
	b->envoi = q2;
	a->reception = q2;
}

bool Simulation::simulerNegociation(NegoAcheteur* n_a, NegoVendeur* n_v)
{
	//lier les negociateurs
	Simulation::lier_negociateurs(n_a, n_v);

	//creation des threads
	bool deal = false;
	std::thread t_vendeur(&NegoVendeur::Negocier, n_v,&deal);
	std::thread t_acheteur(&NegoAcheteur::Negocier, n_a,&deal);
	t_acheteur.join();
	t_vendeur.join();

	if (deal) cout << "Negociation reussie !" << endl;
	else cout << "Echec de la negociation !" << endl;
	return deal;
}
