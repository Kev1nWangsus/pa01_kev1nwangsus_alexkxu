//cards.h
//Authors: Shuo Wang and Alex Xu
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <string>

using namespace std;

class Card
{
    public:
        Card(string cardNum); // constructor
        Card(const Card& source); // copy constructor
        ~Card(); // destructor

        string getValue() const; // getter
        void setValue(string cardNum); // setter

        // overloaded operators:
        friend ostream& operator << (ostream& os, const Card& c1);
        
    private:
        string value;
        Card* next;
};

// non-member overloaded operators
bool operator == (const Card& c1, const Card& c2);

class CardList
{
    public:
        CardList(); // constructor
        CardList(const CardList& source); // copy constructor
        ~CardList(); // destructor

        void append(string value); // append one card to hand (last card)
        void remove(string value); // remove one card from hand
        int getLength(); // return length of the CardList
        bool contains(); // check if the list contains target card
        void printList();

        // overloaded operators:

    private:
        struct Card {
            string value;
            Card* next;
        };

        Card* head;
};

class Player
{
    public:
        Player(string name, CardList hand); // constructor
        Player(const Player& source); // copy constructor
        ~Player(); // destructor;
        void draw();
        void play();
        void check();
        void surrender();

        // overloaded operators:

    private:
        string name;
        CardList hand;
};


#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
