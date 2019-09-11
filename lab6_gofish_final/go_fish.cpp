// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;
//PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main( )
{

    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

/*
    for(int i = 0; i < 52; i++)         //debug - print out whole deck
    {
        Card c = d.dealCard();
        cout << c << endl;
    }
*/
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl << endl;

    Card c1, c2;
    //booking pairs that were in hand after deal
    while(p1.checkHandForBook(c1, c2))
    {
        p1.bookCards(c1, c2);
    }
    while(p2.checkHandForBook(c1, c2))
    {
        p2.bookCards(c1, c2);
    }
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl << endl;

    Card temp = p1.chooseCardFromHand();

    //loop to run the game
    while(d.size() > 0)
    {
        if(p1.getHandSize() != 0) {
            temp = p1.chooseCardFromHand();
            while (p1.checkHandForBook(c1, c2))                  //checks if card drawn last creates pair
            {
                p1.bookCards(c1, c2);
            }
            cout << p1.getName() << " asks - Do you have a " << temp.rankString(temp.getRank()) << "?" << endl;     //p1 turn
            if (p2.rankInHand(temp)) {
                cout << p2.getName() << " says - Yes. I have a " << temp.rankString(temp.getRank()) << "." << endl;     //booking and removing pair
                p1.bookCards(p1.removeCardFromHand(temp), p2.removeCardFromHand(temp));
                cout << p1.getName() << " books the " << temp.rankString(temp.getRank()) << "." << endl;
            } else {
                cout << p2.getName() << " says - Go Fish" << endl;                                                  //drawing new card because no match
                p1.addCard(d.dealCard());
                cout << p1.getName() << " draws " << endl;
            }
        }else{
            cout << p1.getName() << " has no cards in hand" << endl;
            p1.addCard(d.dealCard());
            cout << p1.getName() << " draws " << endl;
        }
        cout << p1.getName() <<" has : " << p1.showHand() << endl;
        cout << p2.getName() <<" has : " << p2.showHand() << endl << endl;


        if(p2.getHandSize() != 0) {
            temp = p2.chooseCardFromHand();
            while (p2.checkHandForBook(c1, c2)) {
                p2.bookCards(c1, c2);
            }
            cout << p2.getName() << " asks - Do you have a " << temp.rankString(temp.getRank()) << "?"
                 << endl;         //p2 turn
            if (p1.rankInHand(temp)) {
                cout << p1.getName() << " says - Yes. I have a " << temp.rankString(temp.getRank()) << "." << endl;
                p2.bookCards(p2.removeCardFromHand(temp), p1.removeCardFromHand(temp));
                cout << p2.getName() << " books the " << temp.rankString(temp.getRank()) << "." << endl;
            } else {
                cout << p1.getName() << " says - Go Fish" << endl;
                p2.addCard(d.dealCard());
                cout << p2.getName() << " draws " << endl;
            }
        }else{
            cout << p2.getName() << " has no cards in hand" << endl;
            p2.addCard(d.dealCard());
            cout << p2.getName() << " draws " << endl;
        }
        cout << p1.getName() <<" has : " << p1.showHand() << endl;
        cout << p2.getName() <<" has : " << p2.showHand() << endl << endl;


    }
    //clear out hands by checking for match one last time
    if(p1.getHandSize() != 0) {
        temp = p1.chooseCardFromHand();
        while (p1.checkHandForBook(c1, c2))                  //checks if card drawn last creates pair
        {
            p1.bookCards(c1, c2);
        }
        cout << p1.getName() << " asks - Do you have a " << temp.rankString(temp.getRank()) << "?" << endl;     //p1 turn
        if (p2.rankInHand(temp)) {
            cout << p2.getName() << " says - Yes. I have a " << temp.rankString(temp.getRank()) << "." << endl;     //booking and removing pair
            p1.bookCards(p1.removeCardFromHand(temp), p2.removeCardFromHand(temp));
            cout << p1.getName() << " books the " << temp.rankString(temp.getRank()) << "." << endl;
        } else {
            cout << p2.getName() << " says - Go Fish" << endl;                                                  //drawing new card because no match
            p1.addCard(d.dealCard());
            cout << p1.getName() << " draws " << endl;
        }
    }
    //find winner
    while (p1.checkHandForBook(c1, c2))                  //book remaining pairs from hands
    {
        p1.bookCards(c1, c2);
    }
    while (p2.checkHandForBook(c1, c2))                  //book remaining pairs
    {
        p2.bookCards(c1, c2);
    }
    cout << p1.getBookSize() << " " << p2.getBookSize() << endl;
    cout << d.size() << endl;
    if(p1.getBookSize() > p2.getBookSize())
    {
        cout << p1.getName() << " is the winner!" << endl;
    }else if(p1.getBookSize() < p2.getBookSize()){
        cout << p2.getName() << " is the winner!" << endl;
    }else{
        cout << "It's a tie!:/" << endl;
    }


    return EXIT_SUCCESS;

}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
   
