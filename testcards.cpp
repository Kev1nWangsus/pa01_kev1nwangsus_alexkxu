// testcards.cpp
// Authors: Shuo Wang and Alex Xu
// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	runAll();
}

void runAll() {
	test_card();
	test_cardlist();
	test_player();
}

// test functions
void test_card() {
	START_TEST("test_card");
	test_card_copy_constructor();
	test_card_operator_double_equal();
	END_TEST("test_card");
}

void test_cardlist() {
	START_TEST("test_cardlist");
	test_cardlist_copy_constructor();
	test_cardlist_append();
	test_cardlist_remove();
	test_cardlist_contains();
	END_TEST("test_cardlist");
}


void test_player() {
	START_TEST("test_player");
	test_player_draw();
	test_player_playCard();
	END_TEST("test_player");
}

// void test_equal() {
// 	START_TEST("test_equal");
// 	test_equal_empty_list();
// 	//test_equal_single_element_list();
// 	END_TEST("test_equal");
// }

// void test_card() {
// 	START_TEST("test_card");
// 	test_card_copy_constructor();
// 	test_card_operator_double_equal();
// 	END_TEST("test_card");
// }

// void test_operator() {
// 	START_TEST("test_card");

// 	test_cardlist_assignment_operator();
// 	END_TEST("test_card");
// }


// specific test functions
// card
void test_card_copy_constructor() {
	Card c1{"s a"};
	Card c2{c1};
	string test_name_1 = "copy constructor test: copy value";
	assertEquals(c1.getValue(), c2.getValue(), test_name_1);

	string test_name_2 = "copy constructor test: deep copy";
	c1.~Card();
	assertEquals(c2.getValue(), "s a", test_name_2);
}

void test_card_operator_double_equal() {
	Card c1{"d j"};
	Card c2{"d j"};

	string testname_1 = "double equal operator test: equility of cards";
	assertEquals(c1==c2, true, testname_1);

	string testname_2 = "double equal operator test: inequility of cards";
	Card c3{"s a"};
	assertEquals(c1==c3, false, testname_2);
}

// cardlist
void test_cardlist_copy_constructor() {
    
}

void test_cardlist_append() { 
	string testname_1 = "append to empty list";
	CardList cl1;
	cl1.append("d j");
	assertEquals(cl1.getHead()->getValue(), "d j", testname_1);

	string testname_2 = "append to single element list";
	cl1.append("s a");
	assertEquals(cl1.getHead()->getNext()->getValue(), "s a", testname_2);
}

void test_cardlist_remove() {
    // honestly this first one is fine as long as nothing crashes
    string testname_1 = "remove from empty list";
    Cardlist cl1;
    assertEquals(cl1.remove("s a"), false, testname_1);

    string testname_2 = "remove head from single element list";
    cl1.append("d j");
    cl1.remove("d j"); 
    assertEquals(cl1.contains("d j"), false, testname_2);

    string testname_3 = "remove card from list";
    cl1.append("d 5");
    cl1.append("d 6");
    cl1.append("s 4");
    cl1.remove("d 6");
    assertEquals(cl1.contains("d 6"), false, testname_3);
}

void test_cardlist_contains() {
    string testname_1 = "empty list";
    Cardlist cl1;
    assertEquals(cl1.contains("s a"), false, testname_1);

    string testname_2 = "1-element list";
    cl1.append("s a");
    assertEquals(cl1.contains("s a"), true, testname_2);

    string testname_2 = "multi-element list";
    cl1.append("d 5");
    cl1.append("c 3");
    cl1.append("h a");
    assertEquals(cl1.contains("c 5"), false, testname_3);
}

void test_cardlist_assignment_operator() {
	CardList cl1;
	cl1.append("d j");
	cl1.append("s a");
	cl1.append("h 1");
	CardList cl2;
	cl2.append("d k");

	string testname_1 = "cardlist assignment operator test: copy value";
	cl2 = cl1;
	assertEquals(cl2.getLength(), 3, testname_1);

	string testname_2 = "cardlist assignment operator test: deep copy";
	cl2.append("h k");
	assertEquals(cl1.getLength(), 3, testname_2);
}


// player
void test_player_draw() {
    string testname_1 = "drawing into empty hand";
    Cardlist cl1;
    Player alex("Alex", cl1);
    alex.draw("s a");
    assertEquals(alex.hand.contains("s a"), true, testname_1);

    string testname_2 = "drawing into non-empty hand";
    alex.draw("h k");
    assertEquals(alex.hand.contains("h k"), true, testname_2);

    string testname_3 = "drawing duplicate into hand";
    alex.draw("h k");
    assertEquals(alex.hand.head->next->next, NULL, testname_3);
}

void test_player_playCard() {
    // testname_1 is fine as long as it doesn't crash
    string testname_1 = "playing from empty hand";
    Cardlist cl1;
    Player kevin("Kevin", cl1);
    kevin.playCard(kevin.hand.head);
    assertEquals(kevin.hand.head, NULL, testname_1);

    string testname_2 = "playing from 1-element hand";
    kevin.draw("s a");
    kevin.playCard(kevin.hand.head);
    assertEquals(kevin.hand.contains("s a"), false, testname_2);

    string testname_3 = "playing from multi-element hand";
    kevin.draw("s a");
    kevin.draw("h k");
    kevin.draw("d j");
    kevin.playCard(kevin.hand.head->next);
    assertEquals(kevin.hand.contains("h k"), false, testname_3);
}


