#include "Negociateur.h"
#include <exception>

double Negociateur::duree_max = 10000;
std::mutex Negociateur::m;

void Negociateur::proposerOffre(double montant)
{
	std::lock_guard<std::mutex> lk(m);
	envoi->push(Message("PROPOSITION", club, montant));
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

Message Negociateur::attendreMessage()
{
	//waiting for msg
	while (reception->empty());

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