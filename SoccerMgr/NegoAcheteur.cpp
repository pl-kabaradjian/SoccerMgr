#include "NegoAcheteur.h"
#include "Chronometre.h"

void NegoAcheteur::Negocier(bool* deal)
{
	auto start = chrono::system_clock::now();
	double elapsed_t = chronometre::elapsed_time(start);

	//Debut de la negociation
	proposerOffre(montant_seuil);
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
			if (offre_courante.montant >= montant_max) {
				if (elapsed_t < duree_max)// on peut encore negocier
				{
					rejeterOffre(offre_courante.montant);
					proposerOffre(offre_courante.montant + elapsed_t);
					offre_courante = attendreMessage();
				}
				else// on refuse et on termine
				{
					rejeterOffre(offre_courante.montant);
					end = true;
				}
			}
			else if (offre_courante.montant < montant_max && offre_courante.montant > montant_seuil) {
				if (elapsed_t < duree_max)// on peut encore negocier
				{
					rejeterOffre(offre_courante.montant);
					proposerOffre(offre_courante.montant / elapsed_t);
					offre_courante = attendreMessage();
				}
				else// on accepte et on termine
				{
					accepterOffre(offre_courante.montant);
					*deal = true;
					end = true;
				}
			}
			else if (offre_courante.montant <= montant_seuil) {
				accepterOffre(offre_courante.montant);//On accepte directement et on termine
				*deal = true;
				end = true;
			}
		}
	}
}

NegoAcheteur::NegoAcheteur(double m_s, Club * c, double max) : Negociateur(m_s, c)
{
	montant_max = max;
}
