# include<iostream>
# include<cmath>
using namespace std;

/*
 Function that calculates Compound Interest. Here P is Principal, r is 
 annual percentage rate and n is number of years.
*/
double compoundInterest(double P, double r, int n)
    {
    double interest = P*pow(1+0.01*r,n)-P;
    return interest;
    }
    
int main()
{
    double principal;
    double interestRate;
    int numberOfYears;
    cout << "How much are you investing?" << endl;
    cin >> principal;
    cout << "What is the annual interest rate?\n";
    cin >> interestRate;
    cout << "How long are you investing(in years)?\n ";
    cin >> numberOfYears;
    double interest = compoundInterest(principal, interestRate, numberOfYears);
    cout << "You will earn " << interest << ".\n";
    return 0; 
} 

