#include "matrix.h"
#include <iostream>
using namespace std;

int main() {
    Matrix A(2, 2);
    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);

    Matrix B(2, 2);
    B.set(0, 0, 1);
    B.set(0, 1, 0);
    B.set(1, 0, 0);
    B.set(1, 1, 1);

    Matrix C = A.multiply(B); // Perform matrix multiplication

    cout << "Matrix A:\n";
    A.print();
    cout << endl;

    cout << "Matrix B:\n";
    B.print();
    cout << endl;

    cout << "Matrix C (A * B):\n";
    C.print();
    cout << endl;

    Matrix m(3,4);  // Matrix with 3 rows and 4 columns.
    m(1,1) = 5;  // Same as doing m.operator()(1,1) = 5. Return value on LHS of assignment operator.
    cout << "m(1,1): " << m(1,1) << endl;

    const Matrix n(3,4);    // Constant Matrix with 3 rows and 4 columns.
    cout << "n(0,2): " << n(0,2) << endl;  // Same as calling n.operator()(0,2) 2nd version of operator.

    return 0;
}
/*
To compile and run multiple c++ files do:
    g++ -o "filename" main.cpp matrix.cpp
    ./"filename"
*/