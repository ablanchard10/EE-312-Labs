//
// Created by Austin on 4/12/2019.
//

#include "player.h"
#include "card.h"
#include "deck.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;


Player::Player()
{
    myName = "";
}

void Player::addCard(Card c)            //adds a card to the hand
{
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2)    //puts pair of cards into mybook for a player
{
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2)
{
    vector<Card>::const_iterator iter1;
    vector<Card>::const_iterator iter2;
    for(iter1 = myHand.begin(); iter1 != myHand.end(); iter1++)
    {
        for(iter2 = iter1 + 1; iter2 != myHand.end(); iter2++)
        {
            if((*iter1).getRank() == (*iter2).getRank())
            {
                c1 = *iter1;
                c2 = *iter2;
                return true;
            }
        }
    }
    return false;
}


//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const
{
    vector<Card>::const_iterator iter;
    for(iter = myHand.begin(); iter != myHand.end(); iter++)
    {
        if(c.getRank() == (*iter).getRank())
        {
            return true;
        }
    }
    return false;
}


//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const
{
    srand(time(0));
    int handsiz = getHandSize();
    int picker = rand() % handsiz;
    return myHand[picker];
}


//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const
{
    vector<Card>::const_iterator iter;

    for(iter = myHand.begin(); iter != myHand.end(); iter++)
    {
        if(c.toString() == (*iter).toString())
        {
            return true;
        }
    }
    return false;

}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c)
{
    Card temp;
    vector<Card>::iterator iter;
    for(iter = myHand.begin(); iter != myHand.end(); iter++)
    {
        if(c.getRank() == (*iter).getRank())
        {
            temp = *iter;
            myHand.erase(iter);
            return temp;
        }
    }


/*    iter = find(myHand.begin(), myHand.end(), c);
    temp = *iter;
    myHand.erase(iter);
    return temp;
*/
}


string Player::showHand() const
{
    string hand;
    vector<Card>::const_iterator iter;
    for(iter = myHand.begin(); iter != myHand.end(); iter++)
    {
        hand = hand + (*iter).toString() + " ";
    }
    return hand;

}

string Player::showBooks() const
{
    string book;
    vector<Card>::const_iterator iter;
    for(iter = myBook.begin(); iter != myBook.end(); iter++)
    {
        book = book + (*iter).toString() + " ";
    }
    return book;
}

int Player::getHandSize() const
{
    return myHand.size();
}

int Player::getBookSize() const
{
    return myBook.size();
}
