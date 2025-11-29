#include <iostream>
#include "bag.h"
using namespace std;

int main() {
    Bag<int> b;

    cout << "Initial bag size: " << b.size() << endl;

    // Insert 10 ones
    for (int i = 0; i < 10; i++)
        b.insert(1);

    cout << "Bag b: " << b << endl;

    // Copy constructor
    Bag<int> b2(b);
    cout << "Bag b2 (copy of b): " << b2 << endl;

    b2.insert(2);
    cout << "After inserting 2 into b2:" << endl;
    cout << "b: " << b << "\nb2: " << b2 << endl;

    // Assignment operator
    b = b2;
    cout << "After assignment b = b2:" << endl;
    cout << "b: " << b << "\nb2: " << b2 << endl;

    // Bag of strings
    Bag<string> sb;
    sb.insert("hello");
    cout << "String bag sb: " << sb << endl;

    // Count, erase, and capacity test
    cout << "Count of 1 in b2: " << b2.count(1) << endl;
    cout << "Erase all 1s from b2: " << b2.erase(1) << endl;
    cout << "b2 after erase: " << b2 << endl;

    // Add b to b2
    b2 += b;
    cout << "b2 after adding b: " << b2 << endl;

    return 0;
}

