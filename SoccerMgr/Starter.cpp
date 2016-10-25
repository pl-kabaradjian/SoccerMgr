#include "Starter.h"

//Cette fonction permet d'instancier des club et des joeurs au demarrage de l'application
void Starter::load(Ligue* ligue)
{
	//Ajout des clubs
	ligue->ajouterClub(new Club("PSG", "Club de Paris", bleu, Date(1970,1,1), new Stade("Parc des princes", 45000, "", gazon),"Paris",""));
	ligue->ajouterClub(new Club("L'Olympique Lyonnais", "Club de Lyon", rouge, Date(1973,4,5), new Stade("Gerland", 50000, "", gazon),"Lyon",""));
	ligue->ajouterClub(new Club("L'Olympique de Marseille", "Club de Marseille", rouge, Date::getDate(), new Stade("Velodrome", 70000, "", tartan),"Marseille",""));
	
	//Ajout des entraineurs et des joueurs
	Club* club_psg = ligue->getListeClub()->at(0);
	Club* club_ol = ligue->getListeClub()->at(1);
	Club* club_om = ligue->getListeClub()->at(2);

	club_psg->ajouter_entraineur(new Entraineur("Blanc","Laurent",45));
	club_psg->ajouter_joueur(new Joueur_autonome("Benarfa","Atem",18, 1.80f, 75,"Corbeil"));
	club_psg->ajouter_joueur(new Joueur_autonome("Elquaidaifi","Nasser",24, 1.80f, 75,"Rambouillet"));
	club_psg->ajouter_joueur(new Joueur_non_autonome("Edison","Khavani",32, 1.80f, 75,"La Defense"));
	club_psg->ajouter_joueur(new Joueur_non_autonome("Matuidi","Blaise",25, 1.80f, 75,"Marseille"));
	club_psg->ajouter_joueur(new Joueur_non_autonome("Meunier","Thomas",22, 1.80f, 80,"Versailles"));

	club_ol->ajouter_entraineur(new Entraineur("Legrand","Jean-Louis",65));
	club_ol->ajouter_joueur(new Joueur_autonome("Valbuena", "Mathieu",36, 1.81f, 81, "Lyon"));
	club_ol->ajouter_joueur(new Joueur_autonome("Grenier", "Clement",32, 1.81f, 82, "Lyon"));
	club_ol->ajouter_joueur(new Joueur_non_autonome("LaCazette", "Alexandre",41, 1.81f, 74, "Annecy"));
	club_ol->ajouter_joueur(new Joueur_non_autonome("Massiege", "Rybus",28, 1.81f, 68, "Saint-Etienne"));
	club_ol->ajouter_joueur(new Joueur_non_autonome("Gonalons", "Maxime",34, 1.81f, 71, "Villefranche"));

	club_om->ajouter_entraineur(new Entraineur("Peuchere","Marius",52));
	club_om->ajouter_joueur(new Joueur_autonome("Lassara", "Diala",42, 1.76f, 82, "Marseille"));
	club_om->ajouter_joueur(new Joueur_autonome("Clinton", "Njie",37, 1.76f, 89, "Les pennes mirabeau"));
	club_om->ajouter_joueur(new Joueur_non_autonome("Bafetimbi", "Gomis",26, 1.76f, 74, "Montpellier"));
	club_om->ajouter_joueur(new Joueur_non_autonome("Machache", "Zinedine",26, 1.76f, 78, "Aubagne"));
	club_om->ajouter_joueur(new Joueur_non_autonome("Vainqueur", "William",29, 1.77f, 86, "Vitrolles"));
		
	//Creation des titres
	Titre* t1 = new Titre("Coupe de France", Date(1998));
	Titre* t2 = new Titre("Coupe d'Europe", Date(2002));
	Titre* t3 = new Titre("Ligue 2", Date(2012));
	Titre* t4 = new Titre("Coupe du monde", Date(1994));
	Titre* t5 = new Titre("Coupe du Japon", Date(2003));
	Titre* t6 = new Titre("Coupe de budget", Date(2005));
	Titre* t7 = new Titre("Coupe de Russie", Date(2009));

	//Ajout des titres aux entraineurs
	club_psg->getTrainer()->ajouter_titre(t1);
	club_psg->getTrainer()->ajouter_titre(t2);
	club_psg->getTrainer()->ajouter_titre(t3);

	club_ol->getTrainer()->ajouter_titre(t4);
	club_ol->getTrainer()->ajouter_titre(t5);

	club_om->getTrainer()->ajouter_titre(t6);
	club_om->getTrainer()->ajouter_titre(t7);

	//Ajout des titres aux clubs
	club_ol->ajouter_titre(t7);
	club_ol->ajouter_titre(t6);
	club_ol->ajouter_titre(t5);

	club_psg->ajouter_titre(t4);
	club_psg->ajouter_titre(t3);

	club_om->ajouter_titre(t2);
	club_om->ajouter_titre(t1);

	//Creation de calendriers
	ligue->getListeCalendrier()->push_back(new Calendrier_rencontre("Hiver 2017"));
	ligue->getListeCalendrier()->push_back(new Calendrier_rencontre("Automne 2016"));
	ligue->getListeCalendrier()->push_back(new Calendrier_rencontre("Ete 2016"));
	Calendrier_rencontre* hiver_2017 = ligue->getListeCalendrier()->at(0);
	Calendrier_rencontre* automne_2016 = ligue->getListeCalendrier()->at(1);
	Calendrier_rencontre* ete_2016 = ligue->getListeCalendrier()->at(2);

	//Ajout de rencontres
	/*hiver_2017->ajouter_rencontre(new Rencontre(Date(),club_ol,club_om));
	hiver_2017->ajouter_rencontre(new Rencontre(Date(), club_ol, club_psg));
	hiver_2017->ajouter_rencontre(new Rencontre(Date(), club_om, club_psg));*/
	
	automne_2016->ajouter_rencontre(new Rencontre(Date(), club_om, club_psg));
	automne_2016->ajouter_rencontre(new Rencontre(Date(), club_ol, club_psg));
	automne_2016->ajouter_rencontre(new Rencontre(Date(), club_ol, club_om));
	
	ete_2016->ajouter_rencontre(new Rencontre(Date(), club_om, club_psg));
	ete_2016->ajouter_rencontre(new Rencontre(Date(), club_ol, club_psg));
	ete_2016->ajouter_rencontre(new Rencontre(Date(), club_ol, club_om));
}
