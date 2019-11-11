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




int main( )
{
	cout << "Creating deck ..." << endl;
	Deck deck;
	cout << "Shuffling deck ..." << endl;
	deck.shuffle();

	cout << "Creating players ..." << endl;
	Player p1("Epicurus"); //
	Player p2("Democritus");
	Player p3("Lucretius");

	//the cards were shuffled and their fates were settled before man could even play the game, how ironic 
	
	//	I saw the best minds of my generation destroyed by madness, starving hysterical naked,
	//dragging themselves through the negro streets at dawn looking for an angry fix,
	//angelheaded hipsters burning for the ancient heavenly connection to the starry dynamo
	// in the machinery of night, who poverty and tatters and hollow-eyed high sat up
	//smoking in the supernatural darkness of cold-water flats floating across the tops of cities contemplating jazz
	//										-Allen Ginsburg
	

    	int numCards = 5;
    
    cout << "Constructing Players\n";
    Player p1("Joe");
    Player p2("Jane");
    
    cout << "Constructing deck\n";
    Deck d;  //create a deck of cards
    cout << "Shuffling deck\n";
    d.shuffle();
    
    cout << "Dealing hands\n";
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    cout << "Hands dealt\n";

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   



