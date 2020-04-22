//cards.cpp
//Authors: Shuo Wang and Alex Xu
//Implementation of the classes defined in cards.h

#include <iostream>
#include "cards.h"
#include <string>

using namespace std;

// CARD FUNCTIONS
Card::Card(string cardNum) {
    value = cardNum;
    next = 0;
};

Card::Card(const Card& source) {
    value = source.value;
    next = source.next;
}

Card::~Card() {
    value = ""; 
    next = 0;
}

string Card::getValue() const {
    return value;
}

void Card::setValue(string cardNum){
    value = cardNum;
}

ostream& operator << (ostream& os, const Card& c1){
    os << c1.value;
    return os;
}

bool operator == (const Card& c1, const Card& c2){
    return c1.getValue() == c2.getValue();
}

// CARDLIST FUNCTIONS
CardList::CardList() : head{0} {};
