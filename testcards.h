// testcards.h
//Authors: Shuo Wang and Alex Xu
//All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it doesn't suit your design but you should definitelty add more
// You should test all possible cornere cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>

using namespace std;

void runAll();

void test_constructor();
void test_copyconstructor();
void test_append();
void test_equal();
void test_card();
void test_destructor();
void test_remove();
void test_contains();

void test_constructor_card();
void test_constructor_cardlist();
void test_constructor_player();

void test_copyconstructor_card();
void test_copyconstructor_cardlist();

void test_append_empty_cardlist(); // A test case for append
void test_append_single_element_cardlist(); // Tests cases should be independent,
            								// small, fast, orthogonal

void test_destructor_card();
void test_destructor_cardlist();
void test_destructor_player();

void test_contains_empty_list();
void test_contains_normal_list();

void test_remove_not_contains();
void test_remove_contains();

void test_equal_empty_list(); // cardlist_operator_double_equal
void test_equal_normal_list();

void test_card_operator_double_equal();
void test_card_operator_ofstream();


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