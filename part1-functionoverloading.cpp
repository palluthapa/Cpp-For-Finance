# include<iostream>
# include<cmath>
using namespace std;

/* 
C++ allows overloading the function name, i.e. it allows more than 
one function to have the same name but the difference is either in
number of parameters or in their type.
The following example shows two function "max" with same name but different
return values and parameter types.
*/

int max(int a, int b)
{
    if (a>b) return a;
    return b;
}

double max(double a, double b)
{
    if (a>b) return a;
    return b;
}

int main()
{
    cout << max(2.0,7.5) << endl; // Calls the second max function.
    return 0; 
} 