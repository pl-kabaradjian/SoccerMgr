#ifndef _NEGOCIATEUR_H
#define _NEGOCIATEUR_H
#include "Message.h"
#include <queue>
#include <mutex>
#include <vector>
#include "Club.h"

class Negociateur {
protected:
	friend class Simulation;
	double montant_seuil;//montant desire
	static double duree_max;
	double elapsed_t;
	Club* club;
	std::queue<Message>* envoi;
	std::queue<Message>* reception;
	static std::mutex m;

	vector<double> hist_montant;
	
	void proposerOffre(double montant);
	void rejeterOffre(double montant);
	void accepterOffre(double montant);

	bool fin_mercato(chrono::system_clock::time_point tp);

	Message attendreMessage();
	
	virtual void Negocier(bool* deal, Message* last_m)=0;
public:
	Negociateur(double m_s, Club* c);
	vector<double> getHistMontant() { return hist_montant;};
};
#endif // !_NEGOCIATEUR_H