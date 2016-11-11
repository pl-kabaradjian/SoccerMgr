#include "NegoAcheteur.h"

void NegoAcheteur::Negocier()
{
}

NegoAcheteur::NegoAcheteur(double m_s, Club * c, double max) : Negociateur(m_s, c)
{
	montant_max = max;
}
