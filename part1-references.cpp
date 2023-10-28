# include<iostream>
using namespace std;

void swapbypointer(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void swapbyreference(int & a, int & b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int& f(int & c) // Function returning reference with reference parameter.
{ 
    c = c+5;
    return c;
}
int main()
{
    /* Reference Variable is an alias(another name for the variable). Reference doesn't 
    take any space in memory whereas Pointer takes space in memory. The reference need
    to be declared and initialised at the same time and can't be changed.    
    */
    int a = 11;
    int & aref = a;  // aref is reference to variable a.
    cout << aref << " " << a << endl ;

    /* Passing arguments to functions can be done by either value, Pointer or Reference.
    For C++ passing arguments via Reference is preferred over Pointer.
    */
    //Passing arguments by Pointer.
    int x = 2;
    int y = 3;
    swapbypointer(&x,&y);
    cout << x << " " << y << endl;

    //Passing arguments by Reference.
    int p = 4;
    int q = 5;
    swapbyreference(p,q);
    cout << p << " " << q << endl;

    // Function returning reference with reference parameter.
    int c = 5;
    for (int i = 0; i < 2; i++)
    {
        f(c)++;
    }
    cout << f(c) << endl;
    return 0;
}