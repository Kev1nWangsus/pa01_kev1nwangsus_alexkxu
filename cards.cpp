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

Card* Card::getNext() const {
    return next;
}

ostream& operator << (ostream& os, const Card& c1){ // overloads <<
    os << c1.value;
    return os;
}

bool operator == (const Card& c1, const Card& c2){ // overloads ==
    return c1.value == c2.value;
}

// CARDLIST FUNCTIONS

CardList::CardList() : head{0} {} // constructor

CardList::CardList(const CardList& source) { // copy constructor
    if (!source.head) {
        head = 0;
    } else {
        Card* n = source.head;
        while (n) {
            append(n->value);
        }
    }
}

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
    if (!contains(c)) return;

    Card* n = head;
    if (*n == c) {
        head = n->next;
        return;
    }
    while (n) {
        if (*(n->next) == c) {
            n->next = n->next->next;
            return;
        }
        n = n->next;
    }
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

Card* CardList::getHead() const {
    return head;
}

bool CardList::contains(const Card& c) const { // checks if an input card exists within implicit CardList
    Card* n = head;
    while (n) {
        if (*n == c) return true;
        n = n->next;
    }
    return false;
}

void CardList::printList() const {
    Card* n = head;
    while(n) {
        cout << n->value << endl;
        n = n->next;
    }
}

CardList& CardList::operator = (const CardList& source){
    if (this == &source) return *this;

    this->~CardList();

    Card* tmp = source.head;
    while (tmp) {
        append(tmp->value);
        tmp = tmp->next;
    }
    return *this;
}

// PLAYER FUNCTIONS
Player::Player(string n, CardList& h){
    name = n;
    hand = h;
}

Player::~Player(){
    name = "";
    hand.~CardList();
}

void Player::setName(string n) {
    name = n;
}

string Player::getName() const {
    return name;
}

void Player::draw(string val) {
    hand.append(val);
}

void Player::playCard(Card& c) {
    cout << getName() << " picked matching card " << c << endl;
    hand.remove(c);
}

void Player::showHand() {
    cout << getName() << "'s cards:" << endl;
    hand.printList();
}

void Player::playWith(Player& p) {
    Card* n = hand.head;
    int turn = 1;
    while (n) {
        if (p.hand.contains(*n)){
            if (turn) {
                playCard(*n);
                p.hand.remove(*n);
                turn--;
            } else {
                // here the player switch his turn to another player
                // use a recursion to represent this switch
                p.playWith(*(this)); 
            }
        }
        n = n->next;
    }
}
