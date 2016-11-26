#include "Simulation.h"
#include <thread>
#include <fstream>

void Simulation::lier_negociateurs(NegoAcheteur* a, NegoVendeur* b)
{
	queue<Message>* q1 = new queue<Message>;
	queue<Message>* q2 = new queue<Message>;
	a->envoi = q1;
	b->reception = q1;
	b->envoi = q2;
	a->reception = q2;
}

result_simu Simulation::simulerNegociation(NegoAcheteur* n_a, NegoVendeur* n_v)
{
	//lier les negociateurs
	Simulation::lier_negociateurs(n_a, n_v);

	//creation des threads
	bool deal = false;
	Message last_m = Message("ERREUR",nullptr,0);
	std::thread t_vendeur(&NegoVendeur::Negocier, n_v,&deal,&last_m);
	std::thread t_acheteur(&NegoAcheteur::Negocier, n_a,&deal,&last_m);
	t_acheteur.join();
	t_vendeur.join();

	//affichage de la negociation
	store_n_plot(n_a, n_v);

	if (deal) cout << "Negociation reussie !" << endl;
	else cout << "Echec de la negociation !" << endl;

	system("Pause");
	return result_simu(deal,last_m.montant);
}

void Simulation::store_n_plot(NegoAcheteur* n_a, NegoVendeur* n_v)
{
		std::ofstream plot_data("plot_data");

		std::vector<double> dataV = n_v->getHistMontant();
		std::vector<double> dataA = n_a->getHistMontant();

		int t = (int)dataV.size();
		for (int i = 0; i < t; i++)
			plot_data << i << " " << dataA[i] << " " << dataV[i] << std::endl;
		std::system("python plot.py");
}
