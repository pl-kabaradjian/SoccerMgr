#ifndef _MESSAGE_H
#define _MESSAGE_H
#include <string>
class Club;

using namespace std;

class Message {
public:
	string type;
	Club* emetteur;
	double montant;

	Message(string type, Club* c, double m);
};
#endif