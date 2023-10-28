# include<iostream>
using namespace std;

int main()
{
    int number;
    char character;
    cout << "Enter any character: \n";
    cin >> character;
    number = (int) character;   // Cast character to integer.
    cout << "The character " << character;
    cout << " is represented as the number " << number;
    cout << " in the computer.\n";
    return 0; 
} 
