#include "Starter.h"

void Starter::load(Ligue* ligue)
{
	ligue->ajouterClub(new Club("PSG", "Club de Paris", bleu, Date(1970,1,1), new Stade("Parc des princes", 45000, "", gazon),"Paris",""));
	ligue->ajouterClub(new Club("L'Olympique Lyonnais", "Club de Lyon", rouge, Date(1973,4,5), new Stade("Gerland", 50000, "", gazon),"Lyon",""));
	ligue->ajouterClub(new Club("L'Olympique de Marseille", "Club de Marseille", rouge, Date::getDate(), new Stade("Velodrome", 70000, "", tartan),"Marseille",""));
}
