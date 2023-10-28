# include<iostream>
using namespace std;

int main()
{
    // If Statement.
    int x = 7;
    if (x > 7) 
    {cout << "x is greater than 7. " << endl;}
    else if (x < 7) 
    {cout << "x is less than 7. " << endl;}
    else 
    {cout << "x is 7. " << endl;}

    // Switch Statement.
    int y = 5;
    switch(x)
    {
    case 1: 
    cout << "y is 1.\n";
    break;
    case 2: 
    cout << "y is 2.\n";
    break;
    case 3:
    cout << "y is 3.\n";
    break;
    default:
    cout << "y is not 1, 2 or 3." << endl;
    }

    // While loop.
    int a = 10;
    while (a < 12)
    {
    cout << "Value of a:" << a << endl;
    a++;
    }

    // do-while loop.
    int n = 3;
    do 
    {
        cout << n << " ";
        n--;
    } 
    while (n != 0);

    // for loop.
    cout << "\n";
    for (int i = 10; i > 0; i--) 
    { 
        if (i == 8) continue;   // "continue" skips to next iteration in the loop.
        cout << "Value of i:" << i << endl; 
        if (i == 2)
        { 
        cout << "Countdown stops";
        break;  // "break" breaks out of the loop.
        }
    }




    return 0;
} 