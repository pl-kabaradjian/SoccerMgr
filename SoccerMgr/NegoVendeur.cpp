#include "NegoVendeur.h"
#include "Chronometre.h"

void NegoVendeur::Negocier(bool* deal)
{
	auto start = chrono::system_clock::now();
	double elapsed_t = chronometre::elapsed_time(start);

	//Debut de la negociation
	Message offre_courante = attendreMessage();
	bool end = false;

	while (!end) {
		elapsed_t = chronometre::elapsed_time(start);
		if (offre_courante.type == "ACCEPTATION") {
			end = true;
			*deal = true;
		}
		else if (offre_courante.type == "REJET") {
			if (elapsed_t < duree_max)// on peut encore negocier
			{
				offre_courante = attendreMessage();
			}
			else// on refuse et on termine
			{
				end = true;
			}
		}
		else if (offre_courante.type == "PROPOSITION") {
			if (offre_courante.montant <= montant_min) {
				if (elapsed_t < duree_max)// on peut encore negocier
				{
					rejeterOffre(offre_courante.montant);
					proposerOffre(montant_seuil / elapsed_t);
					offre_courante = attendreMessage();
				}
				else// on refuse et on termine
				{
					rejeterOffre(offre_courante.montant);
					end = true;
				}
			}
			else if (offre_courante.montant > montant_min && offre_courante.montant < montant_seuil) {
				if (elapsed_t < duree_max)// on peut encore negocier
				{
					rejeterOffre(offre_courante.montant);
					proposerOffre(montant_seuil / elapsed_t);
					offre_courante = attendreMessage();
				}
				else// on accepte et on termine
				{
					accepterOffre(offre_courante.montant);
					*deal = true;
					end = true;
				}
			}
			else if (offre_courante.montant >= montant_seuil) {
				accepterOffre(offre_courante.montant);//On accepte directement et on termine
				*deal = true;
				end = true;
			}
		}
	}
}

NegoVendeur::NegoVendeur(double m_s, Club * c, double min): Negociateur(m_s,c)
{
	montant_min = min;
}
