// This file uses the complex class.
# include <iostream>
# include "complex.h"
using namespace std;

int main()
{
    Complex z1; // default constructor is called.
    cout << z1.Get_Re() << endl;
    Complex z2(5,-7); // Constructor with parameter is called.
    cout << z2 << endl;
    Complex z3;
    cout << z3 << endl;

    z3 = z2; // Same as z3.operator = (z2).
    Complex z4 = z1;    // Copy constructor is called. Same as Complex z4(z1).
    Complex z5 = z2 + z3;   // Same as operator+(z2,z3).
    Complex z6(2,3);
    Complex z7(3,7);
    Complex z8;
    z8 = z6 + z7/z5;
    cout << z8 << endl;
    cout << z6*z7 << endl;
    cout << z6/z7 << endl;
    cout << z2.abs() << endl;
    z8 += z3;
    cout << z8 << endl;
    return 0;
}

/*
To compile and run multiple c++ files do:
    g++ -o "filename" main.cpp complex.cpp
    ./"filename"
*/