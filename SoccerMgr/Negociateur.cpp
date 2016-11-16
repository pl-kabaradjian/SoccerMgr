#include "Negociateur.h"

double Negociateur::duree_max = 10000;

void Negociateur::proposerOffre(double montant)
{
	envoi->push(Message("PROPOSITION", club, montant));
	cout << "Club : " << *club->getNom() << "| Type : PROPOSITION " << "| Montant : " << montant << " €" << endl;
}

void Negociateur::rejeterOffre(double montant)
{
	envoi->push(Message("REJET", club, montant));
	cout << "Club : " << *club->getNom() << "| Type : REJET " << "| Montant : " << montant << " €" << endl;
}

void Negociateur::accepterOffre(double montant)
{
	envoi->push(Message("ACCEPTATION", club, montant));
	cout << "Club : " << *club->getNom() << "| Type : ACCEPTATION " << "| Montant : " << montant << " €" << endl;
}

Message Negociateur::attendreMessage()
{
	while (reception->empty());
	Message m = reception->front();
	reception->pop();
	return m;
}

Negociateur::Negociateur(double m_s, Club * c)
{
	montant_seuil = m_s;
	club = c;
	reception = new queue<Message>;
}
