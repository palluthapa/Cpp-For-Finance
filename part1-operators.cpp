# include<iostream>
using namespace std;

int main()
{
    // Assignment Operator(=)
    int x = 3;
    int y = 5;
    cout << "x: " << x << " y:" << y << endl;
    x = y;
    cout << "x: " << x << " y:" << y << endl;
    y = 7;
    cout << "x: " << x << " y:" << y << endl;

    // Increment & Decrement(++,--) Operator
    int a = 5;
    int b;
    b = ++a;    // a = a+1 then b = a+1 prefix.
    cout << "a: " << a << " b: " << b << endl;

    a = 5;
    b = a++;    // b = a then a = a+1 postfix.  
    cout << "a: " << a << " b: " << b << endl;
    return 0;
} 