#include <iostream>
#include <string>
#include "screen.h"
#include "Ligue.h"
#include "Date.h"
#include "Starter.h"

int main()
{
	//Instanciation de la ligue
	Ligue SoccerLigue("Ligue 1");

	//Chargement des clubs/joueurs/titres
	Starter::load(&SoccerLigue);

	//Affichage du menu principal
	while(true)
	{
		Screen::menuPrincipal(&SoccerLigue);
	}
	return 0;
}