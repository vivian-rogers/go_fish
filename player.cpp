// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

    Player() {
    	myName = "Diogenes";
    }


    string getName() const {
       return myName;
    }
    
    void addCard(Card c) {  //adds a card to the hand
    	myHand.push_back (c);		
    }

    void bookCards(Card c1, Card c2) {
    	myBook.push_back(c1);
	myBook.push_back(c2);
    }

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool checkHandForBook(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    bool rankInHand(Card c) const; 
    
    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card chooseCardFromHand() const {
    	return myHand[rand() % myHand.size()]
    }
    
    //Does the player have the card c in her hand?
    bool cardInHand(Card c) const {
    	for(std::vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++){
		if(c == myHand[it]) {
			return true;
		}
	}
	return false;
    }
    
    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c) {
    	for(std::vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++){
		if(c == myHand[it]) {
			myHand.erase(it);
			return c;
		}
	}
	return 0;
    	
    } 
    
    string showHand() const {
    	string hand;
	for(std::vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++){
		hand = hand + myHand[it].toString()+ " ";
	}
	return hand;
    	
    }
    string showBooks() const {
    	string book;
	for(std::vector<Card>::iterator it = myBook.begin(); it != myBook.end(); it++){
		book = book + myBook[it].toString()+ " ";
	}
	return book;
    	
    } 
    int getHandSize() const {
    	int size;
	for(std::vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++){
		size++;
	}
	return size;
    
    }
    int getBookSize() const {
    	int size;
	for(std::vector<Card>::iterator it = myBook.begin(); it != myBook.end(); it++){
		size++;
	}
	return size;
    }

       
    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
    
    bool sameRankInHand(Card c) const { 
	for(std::vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++){
		if(c.getRank() == myHand[it].getRank())
			return true;
	}
	return size;
    }
    
    


