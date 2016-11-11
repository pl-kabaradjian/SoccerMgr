#include "NegoVendeur.h"

void NegoVendeur::Negocier()
{
}

NegoVendeur::NegoVendeur(double m_s, Club * c, double min): Negociateur(m_s,c)
{
	montant_min = min;
}
