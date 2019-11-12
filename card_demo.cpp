// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 5;
    ofstream log("log.txt");

    cout << "Constructing Players\n";
    log << "Constructing Players\n";
    Player p1("Joe");
    Player p2("Jane");
    
    cout << "Constructing deck\n";
    log << "Constructing deck\n";
    Deck d;  //create a deck of cards
    cout << "Shuffling deck\n";
    log << "Shuffling deck";
    d.shuffle();
    
    cout << "Dealing hands\n";
    log << "Dealing hands\n";
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    cout << "Hands dealt\n";
    log << "Hands dealt\n";

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    log << p1.getName() <<" has : " << p1.showHand() << endl;
    log << p2.getName() <<" has : " << p2.showHand() << endl;
    log.close();

    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   



