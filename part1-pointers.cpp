# include<iostream>
using namespace std;

int g(int x)
{
    return x+2;
}

int main()
{
    int * pNumber; // Declare a pointer variable called pNumber pointing to an int.
    int number = 10; // Declare an int variable and associate it a value.
    pNumber = &number; // Assign the address of the variable number to pointer pNumber.
    cout << *pNumber << endl; // Print the value "pointed to" by the pointer, which is 10.
    cout << &number << endl;
    cout << &pNumber << endl;
    *pNumber = 15; // Assign a new value to where the pointer points to, NOT to the pointer.
    cout << &pNumber << endl;
    cout << *pNumber << endl;
    cout << number << endl;
    int * c;
    c = pNumber;    // Assign Pointer to another Pointer.
    cout << *c << " " << &c  << endl;

    // Dynamic Memory Allocation.

    int * x; // Not initialized
    x = new int; // Allocates some space in memory for variable of type int.
    * x = 17;   // Assigns value 17 to location indicated by pointer x.
    delete x; // Remove the dynamically allocated storage.
    int * y = new int(25);  // Address indicated by pointer y is assigned value of 25.
    cout << *y << " " << &y << endl;
    delete y;
    
    // Non-Constant Pointer to Constant Variable.
    const int a = 5;
    int b = 7;
    const int *aptr = &a;   // Non-const pointer to const variable a.
    // *aptr = 10; // Can't change the constant value.
    aptr = &b;  // Pointer to const variable can point to non-const variable.
    b = 10;

    // Constant Pointer to Non-Constant Variable.
    int d = 3;
    int *const dptr = &d;   // Constant pointer must be declared and initialised at the same time.
    *dptr = 5;  // Can't change the address but can change the value as the variable is Non-const.

    // Constant Pointer to Constant Variable.
    const int e = 6;
    const int *const eptr = &e; // Can't change address or value now.

    // Pointer to Pointers. (Chain of pointers to value)
    int f = 100;
    int *fptr;
    int **fptrptr;
    fptr = &f;  // Points to address of variable f.
    fptrptr = &fptr;  // Points to address of pointer fptr.
    cout << "Value of f: " << f <<endl;
    cout << "Value at *fptr: " << *fptr << endl;
    cout << "Value at **fptrptr: " << **fptrptr << endl;

    // Function Pointers.
    int (*fPtr) (int) = g;  // fptr is a pointer to function g.
    cout << fPtr(5) << endl;    // calls function g through pointer fPtr.
    // Note function name is pointer to function so no need to dereference it using "*".
    // Also no need to use "&" to get function address as in the case of variables.

    return 0;
}