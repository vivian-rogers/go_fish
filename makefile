final: player.o deck.o card.o fish.o
	g++ -o go_fish fish.o player.o deck.o card.o
fish.o: go_fish.cpp deck.h card.h player.h
	g++ -c go_fish.cpp
player.o: player.cpp deck.h card.h
	g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -c card.cpp
