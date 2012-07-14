#ifndef __SUIT_H__
#define __SUIT_H__

class Suit {
public:
	enum Type { DIAMENDS = 0, CLUBS, HEARTS, SPADES };

	Suit(int value, Suit::Type type) { _value = value; _type = type; }

	int value() { return _value; }

	Suit::Type type() { return _type; }

private:
	int _value;
	Suit::Type _type;
};

#endif
