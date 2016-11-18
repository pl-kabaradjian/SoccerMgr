#include "Negociateur.h"
#include <exception>

double Negociateur::duree_max = 10000;
std::mutex Negociateur::m;

void Negociateur::proposerOffre(double montant)
{
	std::lock_guard<std::mutex> lk(m);
	q->push(Message("PROPOSITION", club, montant));
	cout << "Club : " << *club->getNom() << "| Type : PROPOSITION " << "| Montant : " << montant << " €" << endl;
}

void Negociateur::rejeterOffre(double montant)
{
	std::lock_guard<std::mutex> lk(m);
	q->push(Message("REJET", club, montant));
	cout << "Club : " << *club->getNom() << "| Type : REJET " << "| Montant : " << montant << " €" << endl;
}

void Negociateur::accepterOffre(double montant)
{
	std::lock_guard<std::mutex> lk(m);
	q->push(Message("ACCEPTATION", club, montant));
	cout << "Club : " << *club->getNom() << "| Type : ACCEPTATION " << "| Montant : " << montant << " €" << endl;
}

Message Negociateur::attendreMessage()
{
	//waiting for msg
	while (q->empty());

	//getting message and romving it from queue
	std::lock_guard<std::mutex> lk(m);
	try {
		Message msg = q->front();
		return msg;
		q->pop();
	}
	catch(exception e){
		cout << e.what();
	}
}

Negociateur::Negociateur(double m_s, Club * c)
{
	montant_seuil = m_s;
	club = c;
}