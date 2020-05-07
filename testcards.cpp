// testcards.cpp
// Authors: Shuo Wang and Alex Xu
// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <cassert>
#include <vector>

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
    Card c1;
    cl1.remove(c1);
    assertEquals(cl1.getHead(), NULL, testname_1);

    string testname_2 = "remove from single element list";
    cl1.append("d j");
    cl1.remove(cl1.getHead()); 
    assertEquals(c1.contains(
}

void test_cardlist_contains() {

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

}

void test_player_playCard() {

}


