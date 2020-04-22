#include <iostream>
#include <string>
#include "cards.cpp"

using namespace std;

int main(){
    Card c1{"s a"};
    Card c2{"s 2"};
    Card c3{"s a"};
    cout << c1 << endl;
    cout << (c1 == c2) << endl;
    cout << (c1 == c3) << endl;

    CardList cards;
    string vals[5] = {"s a", "d 0", "c j", "d 3", "h q"};
    
    for (int i = 0; i < 5; i++) { cards.append(vals[i]); }
    for (int i = 0; i < 5; i++) 
    {
        cout << "contains " << vals[i] << ": " << cards.contains(vals[i]) << endl;
    }

    cout << "contains " << "\"s 2\"" << ": " << cards.contains(c2) << endl;

    return 0;
}
