# include<iostream>
# include <random>
using namespace std;

int main()
{
    int x,y;
    random_device rd;  // Non-deterministic Seed for random number using random_device.
    mt19937 mt(rd());  // Create instance of the Mersenne Twister and seed it with random device.
    
    x = mt();   // Generates uniform random number.
    y = mt.min();   // Minimum value Mersenne Twister generates.
    cout << "x = " << x << " y = " << y << endl;

    cout << "----------------------------------------------------------" << endl;
    // Now using fixed seed value for code reproducibility.
    int seed = 77;
    mt19937 rn(seed);
    int r1 = rn();
    int r2 = rn();
    int r3 = rn();
    int r[] = {r1,r2,r3};
    for (int j=1;j<4;j++)
    {
        cout << r[j] << ", ";
    }
    return 0;
}