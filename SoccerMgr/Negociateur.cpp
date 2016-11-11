#include "Negociateur.h"

double Negociateur::duree_max = 10000;

Negociateur::Negociateur(double m_s, Club * c)
{
	montant_seuil = m_s;
	club = c;
	reception = new queue<Message>;
}
