#include <iostream>
#include <string>
#include "cards.cpp"

using namespace std;

int main(){
    Card c1{"s a"};
    Card c2{"s 2"};
    Card c3{"s a"};
    cout << c1;
    cout << (c1 == c2);
    cout << (c1 == c3);

    return 0;
}
