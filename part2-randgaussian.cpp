# include<iostream>
# include <cmath>
# include <vector>
# include "part2-randuniform.cpp"
# include "part2-norminv.cpp"
using namespace std;

/*
We have two methods of generating gaussian random variables:
1. Inverse Transform Sampling: First generate uniformly distributed random variable u, Then apply
   the inverse of standard normal cumulative distribution F. Hence, F(u)~N(0,1).
2. Box-Muller Algorithm: First generate two uniformly distributed random variables u1 and u2 in the
   interval (0,1). Then, n1 = sqrt(-2 log(u1)) cos(2 Pi u2) and n2 = sqrt(-2 log(u1)) sin(2 Pi u2) will
   be independent normally distributed random variables with mu = 0 and sigma = 1.
*/

// Function that generates n independent Normally distributed random numbers with mu = 0 and sigma^2 = 1
// using Inverse Transform Sampling.
vector<double> randn(int n)
{
    vector<double> ret = randuniform(n);  // Vector of uniformly distributed random no. in (0,1).
    for (int i=0;i<n;i++)
     {   
         ret[i] = norminv(ret[i]);
     }
     return ret;
}

// Function that generates n independent Normally distributed random numbers with mu = 0 and sigma^2 = 1
// using Box-Muller Algorithm.
vector<double> randnBoxmuller(int n) 
{
    vector<double> ret;
    for (int i = 0; i < n; i++) 
    {
        vector<double> U1 = randuniform(1);
        vector<double> U2 = randuniform(1);

        double N1 = sqrt(-2.0 * log(U1[0])) * cos(2.0 * M_PI * U2[0]);
        double N2 = sqrt(-2.0 * log(U1[0])) * sin(2.0 * M_PI * U2[0]);

        ret.push_back(N1);
        ret.push_back(N2);
    }
    return ret;
}

int main() 
{
    int p = 3;      // p is the Number of random numbers to generate.
    vector<double> z1 = randn(p);    

    // Printing elements of vector z containing Standard Normally distributed random numbers.
    for (int i = 0; i < p; i++)
    {
         cout << "Z1" << i << ": " << z1[i] << endl;
    }
    cout << "----------------------Using Box-Muller below--------------------------------" << endl;

    int n = 2; // (2n) is the Number of random numbers to generate.
    vector<double> z2 = randnBoxmuller(n);

    // Printing elements of vector z containing Standard Normally distributed random numbers.
    for (int i = 0; i < 2*n; i++)
    {
         cout << "Z2" << i << ": " << z2[i] << endl;
    }
   
   return 0;
}
