final: player.o deck.o card.o demo.o
	g++ -otest test demo.o player.o deck.o card.o
demo.o: card_demo.cpp deck.h card.h player.h
	g++ -c card_demo.cpp
player.o: player.cpp deck.h card.h
	g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -c card.cpp
