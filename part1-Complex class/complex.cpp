// Contains definition of member functions. Also called Class File.
# include "complex.h"
# include <iostream>
# include<cmath>

// Constructors Definition.
Complex::Complex(): re(0.0), im(0.0) {}     // Default constructor.

Complex::Complex(double re, double im)    // Constructor with parameter.
{ this -> re = re; this -> im = im;}

Complex::Complex(const Complex & c)     // Copy constructor.
{this -> re = c.re; this -> im = c.im;}

// Member Function Definition.
double Complex::abs() const     // abs function definition.
{return sqrt(re*re + im*im);}

// Setters (Accessor Functions)
void Complex::Set_Re(double x) {re = x;}
void Complex::Set_Im(double y) {im = y;}

// Member Operator Overloading
Complex & Complex::operator = (const Complex & c)   // Overloading (=).
{   // Check for self-assignment
    if (this == & c) {
    return *this;} // Return the current object (*this) unchanged.
    re = c.re; im = c.im;
    return *this;  // returns a reference to the invoking object.
}
Complex & Complex::operator += (const Complex & c)  // Overloading (+=).
{
    // Perform addition and store the result in the current object.
    re += c.re;
    im += c.im;
    // Return the modified object.
    return *this;
}
Complex & Complex::operator -= (const Complex & c)   // Overloading (-=). 
{
    // Subtract the real and imaginary parts of 'c' from the current object.
    re -= c.re;
    im -= c.im;
    // Return the modified object.
    return *this;
}

// Non-member operator overloading.
Complex operator + (const Complex & a, const Complex & b)   // Overloading (+).
{
    Complex sum;
    sum.Set_Re(a.Get_Re() + b.Get_Re());
    sum.Set_Im(a.Get_Im() + b.Get_Im());
    return sum;
}

Complex operator - (const Complex & a, const Complex & b)   // Overloading (-). 
{
    double realPart = a.Get_Re() - b.Get_Re();
    double imagPart = a.Get_Im() - b.Get_Im();
    return Complex(realPart, imagPart);
}

Complex operator * (const Complex & a, const Complex & b)   // Overloading (*).
{
    return Complex(a.Get_Re()*b.Get_Re() - a.Get_Im()*b.Get_Im(),\
                  a.Get_Im()*b.Get_Re() + a.Get_Re()*b.Get_Im());
}

Complex operator / (const Complex & a, const Complex & b)   // Overloading (/). 
{
    double denominator = b.Get_Re() * b.Get_Re() + b.Get_Im() * b.Get_Im();

    if (denominator == 0.0) {
        // Handle division by zero by throwing an exception.
        throw std::runtime_error("Division by zero is not allowed.");
    } else {
        double realPart = (a.Get_Re() * b.Get_Re() + a.Get_Im() * b.Get_Im()) / denominator;
        double imagPart = (a.Get_Im() * b.Get_Re() - a.Get_Re() * b.Get_Im()) / denominator;

        return Complex(realPart, imagPart);
    }
}

std::ostream & operator << (std::ostream & os, const Complex & c)    // Overloading output (<<) operator.
{
    // os << c.Get_Re() << " + " << c.Get_Im() << "i";
    // return os;
    if (c.Get_Re() == 0 && c.Get_Im() == 0)
        {os << 0;}
    else
    {os << c.Get_Re();
    
        if (c.Get_Im() < 0) 
        {os << " - " << -c.Get_Im() << "i";} 
        else {os << " + " << c.Get_Im() << "i";}}
    return os;
}
