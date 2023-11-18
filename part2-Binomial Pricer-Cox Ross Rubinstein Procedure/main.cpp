#include <iostream>
#include "binomial.h"
#include <vector>

using namespace std;

int main() 
{
    // S0 = 110, sigma = 0.15, r = 0.05, T = 2, K = 112.
    /*Approximation of the price of an European Call in the Black-Sholes model*/ 
    
    cout<<"European Call Price: "<<ApproxEuropeanCallBS(110., 0.15, 0.05,2., 112.)<<endl;

    /*Approximation of the price of an European Put in the Black-Sholes model*/
    
    cout<<"European Put Price: "<<ApproxEuropeanPutBS(110., 0.15, 0.05,2.,112.)<<endl;
    
    /*Approximation of the price of an American Call in the Black-Sholes model*/
    
    cout<<"American Call Price: "<<ApproxAmericanCallBS(110., 0.15, 0.05,2.,112.)<<endl;
    
    /*Approximation of the price of an American Put in the Black-Sholes model*/
    
   cout<<"American Put Price: "<<ApproxAmericanPutBS(110., 0.15, 0.05,2.,112.)<<endl;
    
    /*Approximation of the price of an American Put and Call in the Black-Sholes model using the same function*/
    
    Call c;
    
    cout<<"American Call Price: "<< ApproxAmericanCallPutBS(110., 0.15,0.05,2., 112.,c)<<endl;
    
    Put p;
    
    cout<<"American Put Price: "<< ApproxAmericanCallPutBS(110, 0.15,0.05,2., 112.,p)<<endl;
    return 0;
}
/*
To compile and run multiple c++ files do:
    g++ -o main main.cpp binomial.cpp
    ./main
*/