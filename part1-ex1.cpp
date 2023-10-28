/*
Program to compute maximum of two numbers.
*/
# include<iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 10;
    int max =( (a>b)?a:b);  // Conditional ternary operator.
    cout << "The maximum between " << a << " and " << b << " is " << max << ".\n";
    return 0;
} 