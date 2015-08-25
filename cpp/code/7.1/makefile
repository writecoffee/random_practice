OBJS = 7.1.o PokerWithJokersCard.o PokerCard.o Card.o Deck.o Suit.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

7.1: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o 7.1

7.1.o: 7.1.cpp PokerWithJokersCard.o
	$(CC) $(CFLAGS) 7.1.cpp

Suit.o: Suit.cpp Suit.h 
	$(CC) $(CFLAGS) Suit.cpp

Deck.o: Deck.cpp Deck.h Suit.o
	$(CC) $(CFLAGS) Deck.cpp

Card.o: Card.cpp Card.h Deck.o
	$(CC) $(CFLAGS) Card.cpp

PokerCard.o: PokerCard.cpp PokerCard.h Card.o
	$(CC) $(CFLAGS) PokerCard.cpp

PokerWithJokersCard.o: PokerWithJokersCard.cpp PokerWithJokersCard.h PokerCard.o
	$(CC) $(CFLAGS) PokerWithJokersCard.cpp

clean:
	\rm *.o

tar:
	tar cfv 7.1.tar *.cpp *.h
