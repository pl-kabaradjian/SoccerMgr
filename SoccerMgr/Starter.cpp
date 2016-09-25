#include "Starter.h"

void Starter::load(Ligue* ligue)
{
	//Ajout des clubs
	ligue->ajouterClub(new Club("PSG", "Club de Paris", bleu, Date(1970,1,1), new Stade("Parc des princes", 45000, "", gazon),"Paris",""));
	ligue->ajouterClub(new Club("L'Olympique Lyonnais", "Club de Lyon", rouge, Date(1973,4,5), new Stade("Gerland", 50000, "", gazon),"Lyon",""));
	ligue->ajouterClub(new Club("L'Olympique de Marseille", "Club de Marseille", rouge, Date::getDate(), new Stade("Velodrome", 70000, "", tartan),"Marseille",""));
	
	//Ajout des entraineurs et des joueurs
	ligue->getListeClub()->at(0)->ajouter_entraineur(new Entraineur("Blanc","Laurent",45));
	ligue->getListeClub()->at(0)->ajouter_joueur(new Joueur("Benarfa","Atem",18, 1.80f, 75,"Corbeil"));
	ligue->getListeClub()->at(0)->ajouter_joueur(new Joueur("Elquaidaifi","Nasser",24, 1.80f, 75,"Rambouillet"));
	ligue->getListeClub()->at(0)->ajouter_joueur(new Joueur("Edison","Khavani",32, 1.80f, 75,"La Defense"));
	ligue->getListeClub()->at(0)->ajouter_joueur(new Joueur("Matuidi","Blaise",25, 1.80f, 75,"Marseille"));
	ligue->getListeClub()->at(0)->ajouter_joueur(new Joueur("Meunier","Thomas",22, 1.80f, 80,"Versailles"));

	ligue->getListeClub()->at(1)->ajouter_entraineur(new Entraineur("Legrand","Jean-Louis",65));
	ligue->getListeClub()->at(1)->ajouter_joueur(new Joueur("Valbuena", "Mathieu",36, 1.81f, 81, "Lyon"));
	ligue->getListeClub()->at(1)->ajouter_joueur(new Joueur("Grenier", "Clement",32, 1.81f, 82, "Lyon"));
	ligue->getListeClub()->at(1)->ajouter_joueur(new Joueur("LaCazette", "Alexandre",41, 1.81f, 74, "Annecy"));
	ligue->getListeClub()->at(1)->ajouter_joueur(new Joueur("Massiege", "Rybus",28, 1.81f, 68, "Saint-Etienne"));
	ligue->getListeClub()->at(1)->ajouter_joueur(new Joueur("Gonalons", "Maxime",34, 1.81f, 71, "Villefranche"));

	ligue->getListeClub()->at(2)->ajouter_entraineur(new Entraineur("Peuchere","Marius",52));
	ligue->getListeClub()->at(2)->ajouter_joueur(new Joueur("Lassara", "Diala",42, 1.76f, 82, "Marseille"));
	ligue->getListeClub()->at(2)->ajouter_joueur(new Joueur("Clinton", "Njie",37, 1.76f, 89, "Les pennes mirabeau"));
	ligue->getListeClub()->at(2)->ajouter_joueur(new Joueur("Bafetimbi", "Gomis",26, 1.76f, 74, "Montpellier"));
	ligue->getListeClub()->at(2)->ajouter_joueur(new Joueur("Machache", "Zinedine",26, 1.76f, 78, "Aubagne"));
	ligue->getListeClub()->at(2)->ajouter_joueur(new Joueur("Vainqueur", "William",29, 1.77f, 86, "Vitrolles"));

	//Ajout des titres aux entraineurs
	ligue->getListeClub()->at(0)->getTrainer()->ajouter_titre(Titre("Coupe de France", Date(1998)));
	ligue->getListeClub()->at(0)->getTrainer()->ajouter_titre(Titre("Coupe d'Europe", Date(2002)));
	ligue->getListeClub()->at(0)->getTrainer()->ajouter_titre(Titre("Ligue 2", Date(2012)));

	ligue->getListeClub()->at(1)->getTrainer()->ajouter_titre(Titre("Coupe du monde", Date(1994)));
	ligue->getListeClub()->at(1)->getTrainer()->ajouter_titre(Titre("Coupe du Japon", Date(2003)));

	ligue->getListeClub()->at(2)->getTrainer()->ajouter_titre(Titre("Coupe de budget", Date(2005)));
	ligue->getListeClub()->at(2)->getTrainer()->ajouter_titre(Titre("Coupe de Russie", Date(2009)));

}
