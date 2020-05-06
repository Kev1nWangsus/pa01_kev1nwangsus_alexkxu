// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

void runAll(){
  test_append();
  test_equal();
  test_card();
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  //test_equal_single_element_list();
  END_TEST("test_equal");

}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  //test_equal_single_element_list();
  END_TEST("test_card");
}


void test_append_empty_list(){ 

}

void test_append_single_element_list(){ 
  // Tests cases should be independent,
    // small, fast, orthogonal (test for different cases)

}

void test_append_empty_list(){
    string test = "case 0: adding {\"d 1\", \"s a\"";
    CardList l1;
    l1.append("d 1");
    assertEquals(l1.getHead().getValue(), "d 1", test);
}

void test_card_operator_double_equal(){
  // Test to check if == is overloaded for card
}




