#include "NegoAcheteur.h"
#include "Chronometre.h"

void NegoAcheteur::Negocier(bool* deal, Message* last_m)
{
	auto start = chrono::system_clock::now();

	//Debut de la negociation
	proposerOffre(montant_seuil);
	Message offre_courante = attendreMessage();
	bool end = false;

	while (!end) {
		if (offre_courante.type == "ACCEPTATION") {
			end = true;
			*deal = true;
			*last_m = offre_courante;
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
			if (offre_courante.montant >= montant_max) {
				if (!fin_mercato(start))// on peut encore negocier
				{
					rejeterOffre(offre_courante.montant);
					proposerOffre((montant_max-montant_seuil)*(elapsed_t/duree_max)+montant_seuil);//lineaire
					offre_courante = attendreMessage();
				}
				else// on refuse et on termine
				{
					rejeterOffre(offre_courante.montant);
					end = true;
					*last_m = offre_courante;
				}
			}
			else if (offre_courante.montant < montant_max && offre_courante.montant > montant_seuil) {
				if (!fin_mercato(start))// on peut encore negocier
				{
					rejeterOffre(offre_courante.montant);
					proposerOffre(montant_max - (offre_courante.montant + montant_seuil) * elapsed_t/duree_max);
					//proposerOffre(offre_courante.montant*0.95);
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
			else if (offre_courante.montant <= montant_seuil) {
				accepterOffre(offre_courante.montant);//On accepte directement et on termine
				*deal = true;
				end = true;
				*last_m = offre_courante;
			}
		}
		/*else if (offre_courante.type == "FIN") {
			end = true;
		}*/
	}
}

NegoAcheteur::NegoAcheteur(double m_s, Club * c, double max) : Negociateur(m_s, c)
{
	montant_max = max;
}
