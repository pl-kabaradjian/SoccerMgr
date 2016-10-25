#include "Reglement.h"

Reglement::Reglement(int s, string desc, float m_club, float m_joueur)
{
	seuil = s;
	description_droits_joueur = desc;
	montant_transfert = m_club + m_joueur;
	montant_club = m_club;
	montant_joueur = m_joueur;
}

Reglement::Reglement()
{
}
