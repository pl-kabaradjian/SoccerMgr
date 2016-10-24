#ifndef _SCREEN_H
#define _SCREEN_H

#include <iostream>
#include <string>
#include "Ligue.h"

using namespace std;

class Screen {
	static void affiche_choix_liste_club(Ligue * l);
public:
	static void menuPrincipal(Ligue* l);

	//Gestion des clubs
	static void menuClub(Ligue* l);
	static void menuCreaClub(Ligue* l);
	static void menuSupprClub(Ligue* l);
	static void menuListeClub(Ligue * l);
	static void menuBestTrainer(Ligue* l);
	static void menuBestclub(Ligue* l);

	//Gestion des calendriers
	static void menuCalendrier(Ligue* l);
	static void menuCreaCalendrier(Ligue* l);
	static void menuListeCalendrier(Ligue* l);
	static void menuSupprCalendrier(Ligue* l);

	//Gestion des rencontres
	static void menuRencontres(Ligue* l, Calendrier_rencontre* cal);
	static void menuListeRencontres(Calendrier_rencontre* cal);
	static void menuCreaRencontre(Calendrier_rencontre* cal);
	static void menuListeRencontreClub(Ligue* l, Calendrier_rencontre* cal);

	//Jouer le match

	//gestion des transferts
	static void menuTransaction(Ligue* l);
	static void menuTotalTransferts(Ligue* l);
};
#endif
