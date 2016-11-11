#include "Negociateur.h"

double Negociateur::duree_max = 10000;

void Negociateur::proposerOffre(double montant)
{
	envoi->push(Message("PROPOSITON", club, montant);
}

void Negociateur::rejeterOffre(double montant)
{
	envoi->push(Message("REJET", club, montant);
}

void Negociateur::accepterOffre(double montant)
{
	envoi->push(Message("ACCEPTATION", club, montant);
}

Negociateur::Negociateur(double m_s, Club * c)
{
	montant_seuil = m_s;
	club = c;
	reception = new queue<Message>;
}
