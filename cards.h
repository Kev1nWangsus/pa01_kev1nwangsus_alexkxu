// cards.h
// Authors: Shuo Wang and Alex Xu
// All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <string>

using namespace std;

class Card
{
    public:
        Card(string val);         // constructor
        Card(const Card& source); // copy constructor
        ~Card();                  // destructor

        string getValue() const;   // get value
        Card* getNext() const;     // get next card
        void setValue(string val); // setter

        // overloaded operators:
        friend ostream& operator << (ostream& os, const Card& c1); // print card's value
        friend bool operator == (const Card& c1, const Card& c2);  // check if two cards are the same
        
    private:
        string value;
        Card* next;

    friend class CardList;
    friend class Player;
};


class CardList
{
    public:
        CardList();                       // constructor
        CardList(const CardList& source); // copy constructor
        ~CardList();                      // destructor

        void append(string val); // append one card to hand (add to the end)
        void remove(string val); // remove one card from hand,
                                 // do nothing if card doesn't exist in hand

        int getLength() const;           // return length of the CardList
        bool contains(string val) const; // check if the list contains target card
        void printList() const;          // print the whole cardlist
        Card* getHead() const;           // return the head of the cardlist

        // overloaded operators:
        CardList& operator = (const CardList& source); // copy assignment

    private:
        Card* head;

    friend class Player;
};


class Player
{
    public:
        Player(string n, CardList& h); // constructor
        ~Player();                     // destructor;

        string getName() const;   // get name
        CardList getHand() const; // get hand (cardlist type)

        void setName(string n);   // set name
        
        void draw(Card& c);       // draw a card!
        void playCard(Card &c);   // play a card from hand!
        
        string search(Player& p); // check opponent's hand to see if there is any same card
                                  // return first matching card's value if matching
                                  // return "" if no matching card is found
                                  
        void showHand();          // show what cards a player has in hand
        void playWith(Player& p); // find another player to play with
                                  // auto searching embedded!

    private:
        string name;
        CardList hand;
};


#endif
