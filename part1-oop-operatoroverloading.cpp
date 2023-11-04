# include<iostream>
using namespace std;

/*
An operator overloading is a type of polymorphism to give it the user-defined semantics. 
Almost any existing operator in C++ can be overloaded. The exceptions are: conditional (?:),
sizeof, scope (::), member selector (.), and member pointer selector (.*). You can only overload
the operator that exist. You can not create new operators or rename existing operators.
At least one of the operators must be an user-defined type. It is not possible to change the number
of operands an operator could support. All operators keep their default precedence and associativity.

Implementing Operator overloading:
* Member Operator of a Class: It is in the scope of the class in which it is declared. The number
  of parameters to be passed is reduced by one, as the calling object is implicitly supplied is an 
  operand. Unary operators tales no explicit parameters and Binary operators take only one explicit
  parameter.
* Non-Member Operator of a Class (Friend function): It is a non-member function of a class with
  permission to access both private and protected members. More parameters can be passed. Unary 
  operators take one explicit parameter. Binary operators take two explicit parameters.
The main distinction between Member and Non-member is in terms of passing parameters and invoking
object. One clear distinction is the no. of parameters that the operator function receives.
If you are overloading a unary operator, do so as a member function. If you are overloading 
assignement (=), subscript [], function call (()) or member selection (- >), do so as a member function.
If you are overloading a binary operator that modifies its left operand (e.g. operator + =) do so as
a member function. If you are overloading a binary operator that does not modify its left operand 
(e.g. operator +), do so as a Non-member or friend function.
Below is the program to overload ++ Unary Operator.
*/

#include <iostream>
using namespace std;

class Increment 
{
    private:
        int value;

    public:
        // Default Constructor to initialize value to 10.
        Increment() : value(10) {}

        // Accessor Function.
        int get_val()
        {return value;}

        // Overload ++ operator when used as prefix.
        Increment operator ++ ()    // Return type of operator + is Increment class.
        {
            Increment temp;            
            temp.value = ++value;  // Here, value is the value attribute of the calling object.
            return temp;
        }

        // Overload ++ operator when used as postfix.
        Increment operator ++ (int) //(int) is syntax for unary operators as postfix & not a f(n) parameter.
        {
            Increment temp;
            temp.value = value++;  // Here, value is the value attribute of the calling object.
            return temp;
        }

        void output() {
            cout << "Increment: " << value << endl;
        }
};

int main() {
    Increment value1, result;

    // Call the "Increment operator ++ ()" function
    result = ++value1;
    result.output();
    result = ++value1;
    result.output();
    result = ++value1;
    result.output();

    // Call the "Increment operator ++ (int)" function
    cout << "-------------------------------------------" << endl;
    result = value1++;
    result.output();
    result = value1++;
    result.output();
    result = value1++;
    result.output();
    cout << "value1: " << value1.get_val() << endl;

    return 0;
}