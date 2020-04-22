//cards.cpp
//Authors: Shuo Wang and Alex Xu
//Implementation of the classes defined in cards.h

#include <iostream>
#include "cards.h"
#include <string>

using namespace std;

// CARD FUNCTIONS
Card::Card(string cardNum) { // constructor
    value = cardNum;
    next = 0;
};

Card::Card(const Card& source) { // copy constructor
    value = source.value;
    next = source.next;
}

Card::~Card() { // destructor
    value = ""; 
    next = 0;
}

string Card::getValue() const { // getter
    return value;
}

void Card::setValue(string val){ // setter
    value = val;
}

ostream& operator << (ostream& os, const Card& c1){ // overloads <<
    os << c1.value;
    return os;
}

bool operator == (const Card& c1, const Card& c2){ // overloads ==
    return c1.getValue() == c2.getValue();
}

// CARDLIST FUNCTIONS
CardList::CardList() { // constructor
    head = 0;
}

// CardList::CardList() {}

CardList::~CardList() { // destructor
    Card* n = head;
    while (n) {
        n = n->next;
        delete head;
        head = n;
    }
}

void CardList::append(string val) { // appends a new Card obj at the end of implicit CardList
    if (head == 0) { 
        head = new Card(val);
    }
    else {
        Card *n = head;
        while (n->next) { n = n->next; }
        n->next = new Card(val);
    }
}

void CardList::remove(Card& c) {
    if (!head) return;
    if ( !contains(c)) return;

    Card* n = head;

}

int CardList::getLength() const {
    int count = 0;
    Card* n = head;
    while (n) {
        count++; 
        n = n->next;
    }
    return count;
} 

bool CardList::contains(const Card& c) const { // checks if an input card exists within implicit CardList
    Card* n = head;
    while (n) {
        if (*n == c) return true;
        n = n->next;
    }
    return false;
}
