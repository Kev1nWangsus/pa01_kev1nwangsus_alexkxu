// cards.cpp
// Authors: Shuo Wang and Alex Xu
// Implementation of the classes defined in cards.h

#include "cards.h"
#include <iostream>
#include <string>

using namespace std;

// CARD FUNCTIONS
Card::Card(string val) {
    value = val;
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

void Card::setValue(string val){
    value = val;
}

Card* Card::getNext() const {
    return next;
}

ostream& operator << (ostream& os, const Card& c1) {
    os << c1.value;
    return os;
}

bool operator == (const Card& c1, const Card& c2) {
    return c1.value == c2.value;
}

// CARDLIST FUNCTIONS
CardList::CardList() : head{0} {} 

CardList::CardList(const CardList& source) {
    if (!source.head) return;
    
    Card* n = source.head;
    head = new Card{n->value};

    n = n->next;
    while (n) {
        append(n->value);
        n = n->next;
    }
}

CardList::~CardList() { 
    Card* n = head;
    while (n) {
        n = n->next;
        delete head;
        head = n;
    }
}

void CardList::append(string val) {
    if (!head) { 
        head = new Card{val};
    }
    else {
        Card *n = head;
        while (n->next) { n = n->next; }
        Card *c = new Card{val};
        n->next = c;
    }
}

void CardList::remove(string val) {
    if (!head) return;
    if (!contains(val)) return;

    Card* n = head;
    if (n->value == val) {
        n = n->next;
        delete head; 
        head = n;
        return;
    }
    
    while (n->next) {
        if (n->next->value == val) {
            Card* tmp = n->next;
            n->next = n->next->next;
            delete tmp;
            return;
        }
        n = n->next;
    }
}

int CardList::getLength() const {
    int count = 0;
    Card* n = head;
    while (n != nullptr) {
        count++; 
        n = n->next;
    }
    return count;
} 

Card* CardList::getHead() const {
    return head;
}

bool CardList::contains(string val) const {
    Card* n = head;
    while (n) {
        if (n->value == val) return true;
        n = n->next;
    }
    return false;
}

ostream& operator << (ostream& os, const CardList& cl1) {
    Card* n = cl1.head;
    while(n) {
        os << n->getValue() << endl;
        n = n->getNext();
    }
    return os;
}

CardList& CardList::operator = (const CardList& source) {
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
Player::Player(string n, CardList& h) {
    name = n;
    hand = h;
}

Player::~Player(){
    name = "";
    hand.~CardList();
}

string Player::getName() const {
    return name;
}

CardList Player::getHand() const {
    return hand;
}

void Player::setName(string n) {
    name = n;
}

void Player::draw(Card& c) {
    hand.append(c.value);
}

void Player::playCard(Card& c) {
    hand.remove(c.value);
}

string Player::search(Player& p) {
    Card* n = hand.head;
    while (n) {
        if (p.hand.contains(n->value)) {
            return n->value;
        }
        n = n->next;
    }
    return "";
}

void Player::showHand() {
    cout << getName() << "'s cards:" << endl;
    cout << hand;
}

void Player::playWith(Player& p) {
    string matching_card = search(p);
    int turn = 1;
    while (matching_card != "") {
        if (turn) {
            cout << getName() << " picked matching card " << matching_card << endl;
            hand.remove(matching_card);
            p.hand.remove(matching_card);
            matching_card = p.search(*this);
            turn--;
        } else {
            cout << p.getName() << " picked matching card " << matching_card << endl;
            hand.remove(matching_card);
            p.hand.remove(matching_card);
            matching_card = search(p);
            turn++;
        }
    }
}
