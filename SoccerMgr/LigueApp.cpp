#include <iostream>
#include <fstream>
#include <string>
#include "Ligue.h"
#include "boost_export.h"
#include "Starter.h"

#include <boost/serialization/throw_exception.hpp>

int main()
{
	Ligue soccerLigue("Ligue 1");

	//Chargement des donnees
	std::ifstream inputFile("data");
	try
	{
		boost::archive::text_iarchive ia(inputFile);
		ia >> soccerLigue;
		cout << "Data loaded succesfully !" << endl;
	}
	catch (boost::archive::archive_exception e)
	{
		std::cerr << "Error when loading data from file : " << e.what() << endl;
		cout << "Loading default values" << endl;
		//Chargement des clubs/joueurs/titres
		soccerLigue.getListeClub()->clear();
		Starter::load(&soccerLigue);
	}
	system("PAUSE");

	//Lancement du programme
	soccerLigue.run();

	//Sauvegarde des données
	std::ofstream outputFile("data");
	try
	{
		boost::archive::text_oarchive oa(outputFile);
		oa << soccerLigue;
		cout << endl << "Data saved succesfully !" << endl;
	}
	catch (boost::archive::archive_exception e)
	{
		std::cerr << "Error when saving data to file : " << e.what() << endl;
	}
	system("PAUSE");

	return 0;
}