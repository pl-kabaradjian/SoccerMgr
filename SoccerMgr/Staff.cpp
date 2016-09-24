#include "Staff.h"
#include <iostream>

Staff::Staff():Personne("","",0){
}

Staff::Staff(string nom, string prenom, int age, Role r) :Personne(nom, prenom, age) {
	role = r;
}

Staff::~Staff()
{
	cout << "Membre du staff detruit" << endl;
}
