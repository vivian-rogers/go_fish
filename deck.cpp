// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:


Deck::Deck() {
	//goes through and should instantiate eveything
	int count = 0;
	for (int rank = 1; rank < 14; rank++){
		for(int i = 0; i < 4; i++){
			myCards[count] = Card(rank,(Card::Suit(i)));
			count++;
		}
	}
	myIndex = 51;
	srand(time(NULL));
}

void Deck::shuffle() {
	for (int i = 0; i < myIndex * 5; i++) {
		if(myIndex > 1) {
			int deckIndex1 = rand() % myIndex;
			int deckIndex2 = rand() % myIndex;
			Card temp; //implemented a swap.. do not need it elsewhere?
		        temp=myCards[deckIndex1];
			myCards[deckIndex1]=myCards[deckIndex2];
			myCards[deckIndex2]=temp;
		}
	}
}

Card Deck::dealCard() {
	if(myIndex>=0){
		myIndex--;
		return myCards[myIndex+1];
	}
}

int Deck::size() const{
	return myIndex+1; //accounts for 0-indexing
}

