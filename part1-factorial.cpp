# include<iostream>
# include<cmath>
using namespace std;

/* 
Factorial function implementation using recursion. X_n = n*X_n-1, n>=1 
with X_0 = 1 (Stopping Condition).
*/

int factorial (int n)
{ if(n==0)
  { return 1;}
  return n*factorial(n-1);
}

int main()
{
    cout << factorial(5) << endl;
    return 0; 
} 