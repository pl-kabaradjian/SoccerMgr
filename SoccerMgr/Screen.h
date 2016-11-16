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
	//Fonctions d'affichages
	static void afficher_titre(string titre);

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
	static void menuRencontresChoixCalendrier(Ligue * l);
	static void menuRencontres(Ligue* l, Calendrier_rencontre* cal);
	static void menuListeRencontres(Calendrier_rencontre* cal);
	static void menuCreaRencontre(Ligue* l, Calendrier_rencontre* cal);
	static void menuListeRencontreClub(Ligue* l);

	//Jouer le match && Afficher le score
	static void menuJouerRencontre(Calendrier_rencontre * cal);

	//gestion des transferts
	static void menuContrat(Ligue * l);
	static void menuTransfert(Ligue * l);
	static void menuNegociation(Ligue * l);
	static void menuCreaRupture(Ligue * l, Joueur* j, Club* nouv_club, Club* ancien_club);
	static void menuCreaTransfert(Ligue* l, Joueur* j);
	static void menuTotauxClub(Ligue* l);
};
#endif
