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
	static void menuCreaClub(Ligue* l);
	static void menuSupprClub(Ligue* l);
	static void menuListeClub(Ligue * l);
	static void menuBestTrainer(Ligue* l);
	static void menuBestclub(Ligue* l);

	static void menuCalendrier(Ligue* l);
		static void menuCreaCalendrier(Ligue* l);
	static void menuRencontres(Ligue* l);
		static void afficherRencontres(Ligue* l);
		static void menuCreaRencontre(Ligue* l);
		static void menuListeRencontreClub(Ligue* l);
	static void menuTransaction(Ligue* l);
	static void menuTotalTransferts(Ligue* l);
	
};
#endif
