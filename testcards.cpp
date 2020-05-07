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
    CardList cl1;
    cl1.append("s a");
    cl1.append("d j");

    CardList cl2{cl1};
    string testname_1 = "copy constructor test: copy value";
    assertEquals(cl1.getLength(), cl1.getLength(), testname_1);

    string testname_2 = "copy constructor test: deep copy";
    cl2.append("s k");
    assertEquals(cl1.getLength()==cl2.getLength(), false, testname_2);
}

void test_cardlist_append() { 
	string testname_1 = "append test: empty list";
	CardList cl1;
	cl1.append("d j");
	assertEquals(cl1.getHead()->getValue(), "d j", testname_1);

	string testname_2 = "append test: single element list";
	cl1.append("s a");
	assertEquals(cl1.getHead()->getNext()->getValue(), "s a", testname_2);

    string testname_3 = "append test: normal list";
	cl1.append("d j");
	assertEquals(cl1.getHead()->getNext()->getNext()->getValue(), "d j", testname_3);
}

void test_cardlist_remove() {
    // honestly this first one is fine as long as nothing crashes
    string testname_1 = "remove test: empty list";
    CardList cl1;
    cl1.remove("s a");
    assertEquals(cl1.contains("s a"), false, testname_1);

    string testname_2 = "remove test: single element list";
    cl1.append("d j");
    cl1.remove("d j"); 
    assertEquals(cl1.contains("d j"), false, testname_2);

    string testname_3 = "remove test: normal list";
    cl1.append("d 5");
    cl1.append("d 6");
    cl1.append("s 4");

    cl1.remove("d 6");
    assertEquals(cl1.contains("d 6"), false, testname_3);
}

void test_cardlist_contains() {
    string testname_1 = "contains test: empty list";
    CardList cl1;
    assertEquals(cl1.contains("s a"), false, testname_1);

    string testname_2 = "contains test: single element list";
    cl1.append("s a");
    assertEquals(cl1.contains("s a"), true, testname_2);

    string testname_3 = "contains test: normal list";
    cl1.append("d 5");
    cl1.append("c 3");
    cl1.append("h a");
    assertEquals(cl1.contains("c 5"), false, testname_3);
    assertEquals(cl1.contains("h a"), true, testname_3);
}

void test_cardlist_assignment_operator() {
	CardList cl1;
	cl1.append("d j");
	cl1.append("s a");
	cl1.append("h 1");
	CardList cl2;
	cl2.append("d k");

	string testname_1 = "assignment operator test: copy value";
	cl2 = cl1;
	assertEquals(cl2.getLength(), 3, testname_1);

	string testname_2 = "assignment operator test: deep copy";
	cl2.append("h k");
	assertEquals(cl1.getLength(), 3, testname_2);
}


// player
void test_player_draw() {
    string testname_1 = "draw test: empty hand";
    CardList cl1;
    Player alex("Alex", cl1);
    Card c1{"s a"};
    alex.draw(c1);
    assertEquals(alex.getHand().getLength(), 1, testname_1);

    string testname_2 = "draw test: non-empty hand";
    Card c2{"h k"};
    alex.draw(c2);
    assertEquals(alex.getHand().contains("h k"), true, testname_2);
}

void test_player_playCard() {
    CardList cl1;
    Player shuo("Shuo", cl1);
    Card c1{"s a"};

    string testname_1 = "playcard test: single element hand";
    shuo.draw(c1);
    shuo.playCard(*shuo.getHand().getHead());
    assertEquals(shuo.getHand().contains("s a"), false, testname_1);

    string testname_2 = "playcard test: normal hand";
    shuo.draw(c1);
    shuo.draw(c1);
    shuo.draw(c1);
    shuo.playCard(*shuo.getHand().getHead()->getNext());
    assertEquals(shuo.getHand().getLength(), 2, testname_2);
}

void test_player_search(){
    CardList cl1, cl2;
    Player shuo("Shuo", cl1);
    Player alex("Alex", cl2);
    Card c1{"s a"};
    Card c2{"s k"};

    shuo.draw(c1);

    alex.draw(c1);
    alex.draw(c2);

    string testname_1 = "search test: check first same card";
    assertEquals(shuo.search(alex), "s a", testname_1);
    shuo.playCard(c1);
    alex.playCard(c1);
    string testname_2 = "search test: no same card";
    assertEquals(shuo.search(alex), "", testname_2);
}


