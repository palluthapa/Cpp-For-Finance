# include<iostream>
# include<cmath>
using namespace std;

 // User-Defined Functions.
    double miles(double km)
        {
        double m = 1.6 * km;
        return m; 
        }

int main()
{
    // Predefined Functions.
    double x = pow(7,2);
    double y = sqrt(99);
    cout << "x: " << x << " and y: " << y << endl;

    // Implementing User-Defined Functions.
    cout << miles(25) << " miles";
    return 0; 
} 