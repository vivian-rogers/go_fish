// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
Player* nthPlayer(int n);
int exclusiveRand(int caller);




int main( )
{
    	int numCards = 5;
	cout << "Creating deck ..." << endl;
	Deck deck;
	cout << "Shuffling deck ..." << endl;
	deck.shuffle();

	cout << "Creating players ..." << endl;
	Player p1("Epicurus"); //
	Player p2("Democritus");
	Player p3("Lucretius");
	Player playerList[3] = {p1, p2, p3};

	//the cards were shuffled and their fates were settled before man could even play the game, how ironic 
	
	//	I saw the best minds of my generation destroyed by madness, starving hysterical naked,
	//dragging themselves through the negro streets at dawn looking for an angry fix,
	//angelheaded hipsters burning for the ancient heavenly connection to the starry dynamo
	// in the machinery of night, who poverty and tatters and hollow-eyed high sat up
	//smoking in the supernatural darkness of cold-water flats floating across the tops of cities contemplating jazz
	//										-Allen Ginsburg
    	cout << "Dealing hands\n";
    	dealHand(deck, p1, numCards);
    	dealHand(deck, p2, numCards);
	dealHand(deck, p3, numCards);
    	cout << "Hands dealt\n";

    	cout << p1.getName() <<" has : " << p1.showHand() << endl;
    	cout << p2.getName() <<" has : " << p2.showHand() << endl;
    	cout << p3.getName() <<" has : " << p3.showHand() << endl;
	int playernum = 2;

	while( (p1.getHandSize() != 0 )||(p2.getHandSize() != 0 )||(p3.getHandSize() != 0 )){ //while there are cards still 
	       bool turnIsOngoing = true;
	       playernum = ((playernum + 1) % 3) + 1;
	       while(turnIsOngoing) { 
    			cout << p1.getName() <<" has : " << p1.showHand() << endl;
 		   	cout << p2.getName() <<" has : " << p2.showHand() << endl;
 		   	cout << p3.getName() <<" has : " << p3.showHand() << endl;
			

		       	if(playerList[playernum-1].getHandSize() != 0 ){ //if it's still empty, don't do any of the playing stuff and get yo turn skipped
				Card chosenCard = playerList[playernum-1].chooseCardFromHand(); 
				int chosenPlayer = exclusiveRand(playernum)-1; //picks an enemy player
				cout << playerList[playernum-1].getName() << " is asking " << playerList[chosenPlayer].getName() << "for matches with "<< chosenCard.toString() << endl;
				turnIsOngoing = false; //assumes turn is over, might be changed if a match is found
				if(playerList[chosenPlayer].sameRankInHand(chosenCard)) {
					cout << "Debug: found match with " << chosenCard.toString() << endl;
					Card plunderedCard = playerList[chosenPlayer].removeCardSameRank(chosenCard);
					cout << "Debug: match is: " << plunderedCard.toString() << endl;
				       	playerList[playernum-1].removeCardFromHand(chosenCard);
					playerList[playernum-1].bookCards(chosenCard, plunderedCard);
					turnIsOngoing = true;

				}else{
					turnIsOngoing = false;
					cout << "Debug: did not find match with " << chosenCard.toString() << endl;
					if (deck.size()){
						playerList[playernum-1].addCard(deck.dealCard());
					}
				}

			}else{
				turnIsOngoing = false;
				cout << "hand size is zero!!!\n";
				if (deck.size()){
					playerList[playernum-1].addCard(deck.dealCard());
				}
			}
	       }
	}
	//display winner and end game
	//
	//
	//
	//adddddADDDDDDDDDDDDD WINNER 
return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
/*
Player* nthPlayer(int n) { //returns nth player
	switch(n) {
		case 1:
			return &p1;
		case 2:
			return &p2;
		case 3:
		      	return &p3;
	}
}*/

int exclusiveRand(int caller) { //returns any random number from 1 to 3 but NOT the one that called it
	int random = (rand() % 3) + 1;
	while(random != caller) {
		random = (rand() % 3) + 1;
	}
	return random;
}
