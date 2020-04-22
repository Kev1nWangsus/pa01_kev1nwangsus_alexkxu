//cards.cpp
//Authors: Shuo Wang and Alex Xu
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <string>

using namespace std;

Card::Card(const Card& source) {
    value = source.value;
    next = source.next;
}

Card::~Card() {
    value = "";
    next = 0;
}

