# include "myvector.h"
# include <iostream>

// Constructors Definition.
MyVector::MyVector() : size(0), Name(nullptr) {}     // Default Constructor.
// Initialize a MyVector with size 0 and a null pointer.
MyVector::MyVector(int size, int value) : size(size) // Constructor with parameter.
{
    Name = new int[size];
    for (int i = 0; i < size; i++) {
        Name[i] = value;
    }
}
MyVector::MyVector(const MyVector& VectorToCopy):size(VectorToCopy.size)    // Copy Constructor.
{   
    Name = new int[size];   // Allocate Dynamically memory to store value. Name points to first element.
    for (int i = 0; i<size; i++)
        {Name[i] = VectorToCopy.Name[i];} // Initialise i'th element of vector with that of object passed.
}

// Non-Trivial Destructor.
MyVector::~MyVector()
{ 
    delete [] Name; // release pointer-based array's space.
}

// Member Operator Overloading.
MyVector& MyVector::operator=(const MyVector& right)    // Overloading (=).
{ 
    if (&right != this) // Avoid self-assignment. Checks if address of right is different to invoking object.
    {// For arrays of different sizes, deallocate original left-side array, then allocate new left-side array.
        if (size != right.size)
        { 
            delete [] Name; // Release space for invoking object if size are not equal.
            size = right.size;  // Re-initialise size with that of parameter right.
            Name = new int[size];  // Allocate memory for size elements.
        }
        for (int i=0; i<size; i++)  // We do this for both case whether size is same or different.
        {
            Name[i] = right.Name[i]; // Copy array into invoking object.
        }
    }
    return *this;   // Returning invoking object.
}
int & MyVector:: operator [](int subscript) // Overloades([]) when return value can be modified.
{// Check for subscript out-of-range error.
    if (subscript<0 || subscript >=size)
    {   std::cerr << "\nError: Subscript"<<subscript << "out of range" << std::endl;
        exit(1); // Terminates program as subscript out of range.
    }
    return Name[subscript]; // Returns subscript element of Name reference.
}
const int MyVector:: operator [](int subscript) const // Overloades([]) when return value can't be modified.
{// Check for subscript out-of-range error.
    if (subscript<0 || subscript >= size)
    {   std::cerr << "\nError: Subscript"<<subscript << "out of range" << std::endl;
        exit(1);  // Terminates program as subscript out of range.
    }
    return Name[subscript];  // Returns subscript element of Name reference.
}

// Non-member operator overloading.
bool operator == (const MyVector& left, const MyVector& right)   // Overloading(==).
{
    if (left.getsize() != right.getsize())
        {return false;}
    for (int i=0; i<left.getsize(); i++)
        {
            if (left.getname(i)!=right.getname(i))
            {return false;}
        }
    return true;
}
bool operator!=(const MyVector& left, const MyVector& right)     // Overloading(!=). 
{
    return !(left == right); // Returns the opposite of the equality check.
}
std::ostream & operator<< (std::ostream &output, const MyVector& v)  // Overloading output (<<) operator.
{
    for (int i=0; i<v.getsize();i++)
        {std::cout<< v[i] << ",";}
    return output; // Enables cout<<x<<y.
}