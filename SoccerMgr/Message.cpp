#include "Message.h"

Message::Message(string t, Club * c, double m)
{
	if (t == "ACCEPTATION" || t == "REJET" || t == "PROPOSITION") {
		emetteur = c;
		montant = m;
		type = t;
	}
	else {
		emetteur = c;
		montant = -1;
		type = "ERREUR";
	}
}
