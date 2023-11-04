// Header File contains class members and function declarations. Also called Class File.
# pragma once   // Stops same file being included twice.
# include <iostream>
class Complex
{
    private:
        double re;
        double im;
    public:
        Complex();  //Default Constructor.
        Complex(double x, double y);    // Constructor with parameter.
        Complex(const Complex & c);     // Copy constructor.
        ~Complex(){};       // Trivial destructor.

        // Accessor Functions.
        double Get_Re() const;
        double Get_Im() const;
        void Set_Re(double);
        void Set_Im(double);

        double abs () const;     // Member Function abs.
        
        // Member operator overloading.
        Complex & operator = (const Complex & c); // Assignment operator declared as member f(n) of class.
        Complex & operator += (const Complex & c);
        Complex & operator -= (const Complex & c);
    };

// Non-member operator overloading.
Complex operator + (const Complex & a, const Complex & b);
Complex operator - (const Complex & a, const Complex & b);
Complex operator / (const Complex & a, const Complex & b);
Complex operator * (const Complex & a, const Complex & b);
std::ostream & operator << (std::ostream & o, const Complex & c);   // Output operator (<<).

// Inline functions definitions.
inline double Complex :: Get_Re() const
{return re;}
inline double Complex::Get_Im() const
{return im;}