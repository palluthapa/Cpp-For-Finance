# include<iostream>
using namespace std;

int main()
{
    cout << "Size of char : " << sizeof(char)<< " byte" << endl;  //sizeof() operator gives size of data types.
    cout << "Size of int : " << sizeof(int)<< " byte" << endl;
    cout << "Size of signed int : " << sizeof(int signed)<< " byte" << endl;
    cout << "Size of unsigned int : " << sizeof(int unsigned)<< " byte" << endl;
    cout << "Size of short int : " << sizeof(short int)<< " byte" << endl;
    cout << "Size of long int : " << sizeof(long int)<< " byte" << endl;
    cout << "Size of float : " << sizeof(float)<< " byte" << endl;
    cout << "Size of double : " << sizeof(double)<< " byte" << endl;
    return 0;
} 