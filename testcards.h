// testcards.h
// Authors: Shuo Wang and Alex Xu
// All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it doesn't suit your design but you should definitelty add more
// You should test all possible cornere cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>

using namespace std;

void runAll();

// test card class
void test_card();
void test_card_copy_constructor();
void test_card_operator_double_equal();

// test cardlist class
void test_cardlist();
void test_cardlist_copy_constructor();
void test_cardlist_append();
void test_cardlist_remove();
void test_cardlist_contains();
void test_cardlist_assignment_operator();

// test player class
void test_player();
void test_player_draw();
void test_player_playCard();
void test_player_search();


void START_TEST(string testname){
  	cout << "Start " << testname << endl;
}

void END_TEST(string testname) {
  	cout << "End " << testname << endl << endl;
}

void assertEquals(bool expected, bool actual, string testDescription){
	if (expected == actual) {
		cout<<"PASSED: " << testDescription << endl;
	} else {
		cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
	}
}

void assertEquals(string expected, string actual, string testDescription){
	if (expected == actual) {
		cout<<"PASSED: " << testDescription << endl;
	} else {
		cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
	}
}

void assertEquals(int expected, int actual, string testDescription){
	if (expected == actual) {
		cout<<"PASSED: " << testDescription << endl;
	} else {
		cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
	}
}

// You should add more assertEquals function for your classes. For example, Node/Card class

void assertEquals(Card *expected, Card *actual, string testDescription){
  	if (expected == actual) {
    	cout << "PASSED: " << testDescription << endl;
  	} else {
    	cout << "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  	}
}

void assertEquals(CardList *expected, CardList *actual, string testDescription)
{
    if (expected == actual) {
		cout << "PASSED: " << testDescription << endl;
	} else {
		cout << "  FAILED: " << testDescription << endl << "   Expected: " << expected << " Actual: " << actual << endl;
	}
}

#endif