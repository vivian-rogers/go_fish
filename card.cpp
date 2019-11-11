// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:

Suit Card::getSuit() const{
	return mySuit;
}

Card::Card() {
	myRank = 1;
	mySuit = spades;
}

Card::Card(int rank, Suit s) {
	myRank = rank;
	mySuit = s;
}

string Card::toString(){
	return (rankString(myRank) + suitString(mySuit));
}

bool Card::sameSuitAs(const Card& c) const{
	return (mySuit == c.getSuit());
}

int Card::getRank() const{
	return myRank;	
}

string Card::suitString(Suit s) const {
	switch(s) {
		case spades:
			return "s";
		case hearts:
			return "h";
		case diamonds:
			return "d";
		case clubs:
			return "c";
	}
}

string Card::rankString(int r) {
	switch(r) {
		case 1:
			return "A";
		case 2:
			return "2";
		case 3:
			return "3";
		case 4:
			return "4";
		case 5:
			return "5";
		case 6:
			return "6";
		case 7:
			return "7";
		case 8:
			return "8";
		case 9:
			return "9";
		case 10:
			return "10";
		case 11:
			return "J";
		case 12:
			return "Q";
		case 13:
			return "K";

	}
}


bool Card::operator ==(const Card& rhs) const {
	return ( (myRank == rhs.getRank()) && this.sameSuitAs(rhs)); 
}

bool Card::operator !=(const Card& rhs) const {
	return ~(*this == rhs);
}

Card::~Card() {}
