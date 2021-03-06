#include "NegoVendeur.h"
#include "Chronometre.h"

void NegoVendeur::Negocier(bool* deal, Message* last_m)
{
	auto start = chrono::system_clock::now();

	//Debut de la negociation
	Message offre_courante = attendreMessage();
	bool end = false;

	while (!end) {
		if (offre_courante.type == "ACCEPTATION") {
			end = true;
			*last_m = offre_courante;
			*deal = true;
		}
		else if (offre_courante.type == "REJET") {
			if (!fin_mercato(start))// on peut encore negocier
			{
				offre_courante = attendreMessage();
			}
			else// on refuse et on termine
			{
				rejeterOffre(offre_courante.montant);
				end = true;
				*last_m = offre_courante;
			}
		}
		else if (offre_courante.type == "PROPOSITION") {
			if (offre_courante.montant <= montant_min) {
				if (!fin_mercato(start))// on peut encore negocier
				{
					rejeterOffre(offre_courante.montant);
					proposerOffre(3*montant_min*(1-elapsed_t/duree_max));
					offre_courante = attendreMessage();
				}
				else// on refuse et on termine
				{
					rejeterOffre(offre_courante.montant);
					end = true;
					*last_m = offre_courante;
				}
			}
			else if (offre_courante.montant > montant_min && offre_courante.montant < montant_seuil) {
				if (!fin_mercato(start))// on peut encore negocier
				{
					rejeterOffre(offre_courante.montant);
					proposerOffre(offre_courante.montant*(1.75 - elapsed_t/duree_max));
					offre_courante = attendreMessage();
				}
				else// on accepte et on termine
				{
					accepterOffre(offre_courante.montant);
					*deal = true;
					end = true;
					*last_m = offre_courante;
				}
			}
			else if (offre_courante.montant >= montant_seuil) {
				accepterOffre(offre_courante.montant);//On accepte directement et on termine
				*deal = true;
				end = true;
				*last_m = offre_courante;
			}
		}
	}
}

NegoVendeur::NegoVendeur(double m_s, Club * c, double min): Negociateur(m_s,c)
{
	montant_min = min;
}
