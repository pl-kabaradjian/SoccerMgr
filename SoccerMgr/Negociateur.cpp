#include "Negociateur.h"
#include "Chronometre.h"
#include <exception>

double Negociateur::duree_max = 3000;
std::mutex Negociateur::m;

void Negociateur::proposerOffre(double montant)
{
	std::lock_guard<std::mutex> lk(m);
	envoi->push(Message("PROPOSITION", club, montant));
	hist_montant.push_back(montant);
	cout << "Club : " << *club->getNom() << "| Type : PROPOSITION " << "| Montant : " << montant << " $" << endl;
}

void Negociateur::rejeterOffre(double montant)
{
	std::lock_guard<std::mutex> lk(m);
	envoi->push(Message("REJET", club, montant));
	cout << "Club : " << *club->getNom() << "| Type : REJET " << "| Montant : " << montant << " $" << endl;
}

void Negociateur::accepterOffre(double montant)
{
	std::lock_guard<std::mutex> lk(m);
	envoi->push(Message("ACCEPTATION", club, montant));
	cout << "Club : " << *club->getNom() << "| Type : ACCEPTATION " << "| Montant : " << montant << " $" << endl;
}

bool Negociateur::fin_mercato(chrono::system_clock::time_point tp)
{
	elapsed_t = chronometre::elapsed_time(tp);
	if (elapsed_t > duree_max)
		return true;
	else
		return false;
}

Message Negociateur::attendreMessage()
{
	//waiting for msg
	while (reception->empty()) {
	}

	//temporisation
	//std::this_thread::sleep_for(std::chrono::milliseconds(50));

	//getting message and removing it from queue
	std::lock_guard<std::mutex> lk(m);
	try {
		Message msg = reception->front();
		reception->pop();
		return msg;
	}
	catch(exception e){
		cout << e.what();
		return Message("Erreur", nullptr, 0);
	}
}

Negociateur::Negociateur(double m_s, Club * c)
{
	montant_seuil = m_s;
	club = c;
}