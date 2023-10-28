# include<iostream>
using namespace std;

int main()
{
    int a;
    int b;
    cout << "Enter a number: \n";
    cin >> a;
    cout << "Enter another number: \n";
    cin >> b;
    double c = (static_cast<double> (a))/b; //Casting done to perform real no. division.
    cout << "The division of a/b is " << c << endl;
    return 0; 
} 