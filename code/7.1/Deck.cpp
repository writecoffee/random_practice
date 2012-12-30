#include "Deck.h"

Deck::Deck() {
	for (int i = 0; i < 52; ++i) {
		_cards[i] = new Card(new Suit((i + 2) % 13, Suit::DIAMENDS));
	}
}

void Deck::shuffle() {

}

char Deck::_values[][2] = {
	"-", "-", "2", "3", "4", "5", "6", "7", "8",
	"9", "T", "J", "Q", "K", "A", "B", "R"
};

char Deck::_suits[][2] = {
	"D", "C", "H", "S"
};
