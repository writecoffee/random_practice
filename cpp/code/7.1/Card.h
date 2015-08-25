#ifndef __CARD_H__
#define __CARD_H__

#include <cstring>
#include "Suit.h"
#include "Deck.h"

class Card {
public:
	Card(Suit *suit);
	int rank();
	Suit *suit();

protected:
	char _name[3];
	int _rank;
	Suit *_suit;
};

#endif
