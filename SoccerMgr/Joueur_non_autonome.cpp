#include "Joueur_non_autonome.h"
#include "Date.h"

int Joueur_non_autonome::get_annees_anciennete()
{
	int anciennete = Date::getDate().getYear() -this->date_anciennete.getYear();
	return anciennete;
}
