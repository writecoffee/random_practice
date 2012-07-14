#include "Card.h"

Card::Card(Suit *suit) {
	_suit = suit; 

	// Ace should be mapped to "A"
	if (_suit->value() == 1) {
		strcat(_name, Deck::values()[14]);
		strcat(_name, Deck::suits()[_suit->type()]);
	} else {
		strcat(_name, Deck::values()[_suit->value()]);
		strcat(_name, Deck::suits()[_suit->type()]);
	}

	_rank = _suit->value();
}

int Card::rank() {
	return _rank;
}

Suit *Card::suit() {
	return _suit;
}
