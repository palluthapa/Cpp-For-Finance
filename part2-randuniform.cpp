# include<iostream>
# include <random>
# include <vector>
using namespace std;

/* Below if we use keyword static so that variable or function can only be used in the current source 
   file so that we can reuse the same name in other source files if desired.
   static mt19937 mersenneTwister(random_device{}()); 
*/
mt19937 mersenneTwister(random_device{}());     // Creates object mersenneTwister belonging to class mt19937.
// Function that generates n independent uniformly distributed random numbers.
vector<double> randuniform (int n)
{
    vector<double> ret(n,0.0);  // Vector of size n with all elements zero.
    for (int i=0;i<n;i++)
    {
        ret[i] = (mersenneTwister() + 0.5)/(mersenneTwister.max() + 1.0);   // Normalising such that
                                                                // random variable is between 0 and 1.
    }
    return ret;     // Returns vector of Uniform random number between 0 and 1.
}
