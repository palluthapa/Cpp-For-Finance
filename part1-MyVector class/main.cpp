#include "myvector.h"
#include <iostream>
using namespace std;

int main() {
    // Test MyVector class
    MyVector v1(3,5); // Create a vector of size 3 with all elements set to 5.
    MyVector v2(3,2); // Create another vector of size 3 with all elements set to 2.

    // Test member operator overloading (indexing)
    v1[0] = 10;
    cout << "v1[0] = " << v1[0] << endl;

    // Test non-member operator overloading (equality)
    if (v1 == v2) {
        cout << "v1 and v2 are equal." << endl;
    } else {
        cout << "v1 and v2 are not equal." << endl;
    }

    cout << v1 << endl;
    cout << v2 << endl;

    return 0;
}
