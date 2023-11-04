# pragma once   // Stops same file being included twice.
# include <iostream>

class MyVector
{
    private:
        int size; // the size.
        int* Name; // Pointer to the first element of pointer-based array.
    public:
        MyVector();     // Default constructor.
        MyVector(int size, int value = 0); // Constructor with parameter.
        MyVector(const MyVector&);  // Copy constructor;
        ~MyVector();        // Non-trivial Destructor.

        // Accessor Functions.
        int getsize() const;        // Returns size;
        int getname(int i) const;   // Returns element i.

        // Member operator overloading.
        MyVector & operator = (const MyVector &);// Assignment operator which returns reference to vector.
        int& operator [] (int);  // Subscript operator for non-const objects return modifiable lvalue.
        const int operator [] (int) const; // Subscript operator for const objects returns non-modifiable rvalue.
};

// Non-member operator overloading.
bool operator == (const MyVector& left, const MyVector& right );    // Equality operator(==).
bool operator != (const MyVector& left, const MyVector& right);     // Inequality operator (!=).
std::ostream& operator<< (std::ostream& out, const MyVector& v);    // Output operator(<<).

// Inline functions definitions.
inline int MyVector :: getsize() const
{return size;}
inline int MyVector::getname(int i) const 
{
    if (i < 0 || i >= size) 
    {
        std::cerr << "\nError: Subscript " << i << " out of range" << std::endl;
        exit(1);
    }
    return Name[i];
}
