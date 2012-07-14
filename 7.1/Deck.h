#ifndef __DECK_H__
#define __DECK_H__

#include "Card.h"
#include "Suit.h"


class Card;

class Deck {
private:
	static char _values[][2];
	static char _suits[][2];
	Card *_cards[54];

public:
	typedef char Token[2];
	static const Token *values() { return _values; }
	static const Token *suits() { return _suits; }
	Deck();
	virtual void shuffle();
};

#endif
