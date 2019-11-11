// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"


using namespace std;

//`Player::Player() {
//    	myName = "Diogenes";
//    }


//    string Player::getName() const {
//       return myName;
//    }
    
    void Player::addCard(Card c) {  //adds a card to the hand
    	myHand.push_back (c);		
    }

    void Player::bookCards(Card c1, Card c2) {
    	myBook.push_back(c1);
	myBook.push_back(c2);
    }

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    //bool checkHandForBook(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    //bool rankInHand(Card c) const; 
    
    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card Player::chooseCardFromHand() const {
    	return myHand.at(rand() % myHand.size());
    }
    
    //Does the player have the card c in her hand?
    bool Player::cardInHand(Card c) const {
    	for(int i = 0; i < myHand.size(); i++){
		if(c == myHand.at(i)) {
			return true;
		}
	}
	return false;
    }
    
    //Remove the card c from the hand and return it to the caller
    Card Player::removeCardFromHand(Card c) {
    	for(int i = 0; i < myHand.size(); i++){
		if(c == myHand.at(i)) {
			myHand.erase(myHand.begin() + i);
			return c;
		}
	}
	//return 0; better hope that it finds the card !
    	
    } 
    
    string Player::showHand() const {
    	string hand;
	for(int i = 0; i < myHand.size(); i++){
		hand = hand + myHand.at(i).toString()+ " ";
	}
	return hand;
    	
    }
    string Player::showBooks() const {
    	string book = "";
	for(int i = 0; i < myHand.size(); i++){
		book = book + myBook.at(i).toString()+ " ";
	}
	return book;
    	
    } 
    int Player::getHandSize() const {
    	//int size;
	//for(int i = 0; i < myHand.size(); i++){
	//	size++;
	//}
	return myHand.size();
    
    }
    int Player::getBookSize() const {
    	//int size;
	//for(int i = 0; i < myBook.size(); i++){
	//	size++;
	//}
	return myBook.size();
    }

       
    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    //bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
    
    bool Player::sameRankInHand(Card c) const { 
	for(int i = 0; i < myHand.size(); i++){
		if(c.getRank() == myHand.at(i).getRank())
			return true;
	}
	return false;
    }
    
    


