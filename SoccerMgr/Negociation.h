#ifndef _NEGOCIATION_H
#define _NEGOCIATION_H
#include "Negociateur.h"
#include "Message.h"
#include <queue>

class Negociation {
protected:
	virtual void proposerOffre(double montant)=0;
	virtual void rejeterOffre(double montant)=0;
	virtual void accepterOffre(double montant)=0;
};
#endif // !_NEGOCIATION_H
