#ifndef _NEGOCIATEUR_H
#define _NEGOCIATEUR_H
#include "Message.h"
#include <queue>

class Club;

class Negociateur {
protected:
	friend class Simulation;
	double montant_seuil;
	static double duree_max;
	Club* club;
	std::queue<Message>* envoi;
	std::queue<Message>* reception;
	virtual void Negocier()=0;
public:
	Negociateur(double m_s, Club* c);
};
#endif // !_NEGOCIATEUR_H