#include <iostream>
#include <string>
#include "Ligue.h"

using namespace std;

#ifndef _SCREEN_H
#define _SCREEN_H
class Screen {
	static void affiche_choix_liste_club(Ligue * l);
public:
	static void menuPrincipal(Ligue* l);
	static void menuCreaClub(Ligue* l);
	static void menuSupprClub(Ligue* l);
	static void menuListeClub(Ligue * l);
	static void menuBestTrainer(Ligue* l);
	static void menuBestclub(Ligue* l);
};
#endif