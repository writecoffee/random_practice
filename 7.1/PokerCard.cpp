#include "PokerCard.h"

PokerCard::PokerCard(Suit *suit) : Card(suit) {
	if (suit->value() == 1) { Card::_rank = 14; }
}
