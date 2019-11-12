// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
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
	ofstream fout("gofish_results.txt");
	fout << "Creating deck ..." << endl;
	Deck deck;
	fout << "Deck size: " << deck.size() << endl;
	fout << "Shuffling deck ..." << endl;
	deck.shuffle();

	fout << "Creating players ..." << endl;
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
    	fout << "Dealing hands\n";
    	dealHand(deck, playerList[0], numCards);
    	dealHand(deck, playerList[1], numCards);
	dealHand(deck, playerList[2], numCards);
    	fout << "Hands dealt\n";
	fout << "Deck size: " << deck.size() << endl;

	for (int i = 0; i < 3; i++) {
		fout << "player" << i+1 << " has " << playerList[i].getHandSize() << " cards in hand\n";
	}
    	fout << playerList[0].getName() <<" has : " << playerList[0].showHand() << endl;
    	fout << playerList[1].getName() <<" has : " << playerList[1].showHand() << endl;
    	fout << playerList[2].getName() <<" has : " << playerList[2].showHand() << endl;
	fout << "player 1 has a " << playerList[0].chooseCardFromHand().toString() << "\n";
	int playernum = 2;
	fout << "Deck size: " << deck.size() << endl;

	while( (playerList[0].getHandSize() != 0 )||(playerList[1].getHandSize() != 0 )||(playerList[2].getHandSize() != 0 )){ //while there are cards still 
	       bool turnIsOngoing = true;
//	fout << "Deck size: " << deck.size() << endl;
	       playernum = ((playernum + 1) % 3) + 1;
	       while(turnIsOngoing) { 
    			fout << playerList[0].getName() <<" has : " << playerList[0].showHand() << endl;
 		   	fout << playerList[1].getName() <<" has : " << playerList[1].showHand() << endl;
 		   	fout << playerList[2].getName() <<" has : " << playerList[2].showHand() << endl;
//	fout << "Deck size: " << deck.size() << endl;
			
			fout << "current player hand size: " << playerList[playernum-1].getHandSize() << endl;
		       	if(playerList[playernum-1].getHandSize() != 0 ){ //if it's still empty, don't do any of the playing stuff and get yo turn skipped
				Card chosenCard = playerList[playernum-1].chooseCardFromHand(); 
				int chosenPlayer = exclusiveRand(playernum)-1; //picks an enemy player
//	fout << "Deck size: " << deck.size() << endl;
				fout << playerList[playernum-1].getName() << " is asking " << playerList[chosenPlayer].getName() << " for matches with "<< chosenCard.toString() << endl;
				turnIsOngoing = false; //assumes turn is over, might be changed if a match is found
				if(playerList[chosenPlayer].sameRankInHand(chosenCard)) {
					fout << "Debug: found match with " << chosenCard.toString() << endl;
					Card plunderedCard = playerList[chosenPlayer].removeCardSameRank(chosenCard);
//					fout << "Debug: match is: " << plunderedCard.toString() << endl;
				       	playerList[playernum-1].removeCardFromHand(chosenCard);
					playerList[playernum-1].bookCards(chosenCard, plunderedCard);
					turnIsOngoing = true;

				}else{
					turnIsOngoing = false;
					fout << "Debug: did not find match with " << chosenCard.toString() << endl;
					fout << "Debug: deck.size() " << deck.size() << endl;
					if (deck.size()){
						fout << "Drawing a card...\n";
						playerList[playernum-1].addCard(deck.dealCard());
						if( playerList[playernum-1].rankInHand(chosenCard) ){ 
							Card temp = playerList[playernum-1].removeCardSameRank(chosenCard);
							playerList[playernum-1].bookCards(temp,chosenCard);
						}						
 					}
				}

			}else{
				turnIsOngoing = false;
				fout << "hand size is zero!!!\n";
				if (deck.size()){
					fout << "Drawing a card...\n";
					playerList[playernum-1].addCard(deck.dealCard());
				}
			}
	       }
	}
	//display winner and end game
	if ((playerList[0].getBookSize() > playerList[1].getBookSize()) && (playerList[0].getBookSize() > playerList[2].getBookSize())) {
		fout << "Player 1 wins\n";
	}else if ((playerList[1].getBookSize() > playerList[0].getBookSize()) && (playerList[1].getBookSize() > playerList[2].getBookSize())) {
		fout << "Player 2 wins\n";
	}else if ((playerList[2].getBookSize() > playerList[1].getBookSize()) && (playerList[2].getBookSize() > playerList[0].getBookSize())) {
		fout << "Player 3 wins\n";
	}else{
		fout << "It's a draw\n";
	}

	//
	//
	//adddddADDDDDDDDDDDDD WINNER 
	fout.close();
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
			return &playerList[0];
		case 2:
			return &playerList[1];
		case 3:
		      	return &playerList[2];
	}
}*/

int exclusiveRand(int caller) { //returns any random number from 1 to 3 but NOT the one that called it
	int random = (rand() % 3) + 1;
	while(random == caller) {
		random = (rand() % 3) + 1;
	}
	return random;
}
