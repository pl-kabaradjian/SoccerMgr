#include <iostream>
#include <string>
#include "screen.h"
#include "Ligue.h"
#include "Date.h"
#include "Starter.h"

int main()
{
	Ligue SoccerLigue("Ligue 1");
	Starter::load(&SoccerLigue);
	while(true)
	{
		Screen::menuPrincipal(&SoccerLigue);
	}
	return 0;
}