# include<iostream>
#include <cmath>
using namespace std;

int main()
{
    double number;
    cout << "Enter any Real number: \n";
    cin >> number;
    cout.setf(ios::fixed);  // Value will be displayed in Fixed point notation.
    cout.precision(2);  // Set precision to 2 decimal place.
    cout << "The square root of "<< number <<" is approximately ";
    cout << sqrt(number)<< ".\n";
    cout.setf(ios::scientific);
    cout.precision(2);
    cout << "The square root of "<< number <<" is approximately ";
    cout << sqrt(number)<< ".\n";
    return 0;
} 