#ifndef _NEGOCIATEUR_H
#define _NEGOCIATEUR_H
#include "Message.h"
#include <queue>
#include "Club.h"

class Negociateur {
protected:
	friend class Simulation;
	double montant_seuil;//montant desire
	static double duree_max;
	Club* club;
	std::queue<Message>* envoi;
	std::queue<Message>* reception;
	
	void proposerOffre(double montant);
	void rejeterOffre(double montant);
	void accepterOffre(double montant);

	Message attendreMessage();
	
	virtual void Negocier(bool* deal)=0;
public:
	Negociateur(double m_s, Club* c);
};
#endif // !_NEGOCIATEUR_H