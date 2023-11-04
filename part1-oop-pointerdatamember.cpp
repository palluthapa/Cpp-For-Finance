# include<iostream>
#include <cstring>
using namespace std;
/*
Every class that has a pointer data member should include the following member functions:
• a destructor.
• a copy constructor.
• operator= (assignement).
All three must be included.
Below we have a StringWithPointer Class that contains a char* pointer to store a 
dynamically allocated string.
*/

class StringWithPointer 
{
    private:
        char* str;

    public:
        // Default constructor.
        StringWithPointer() : str(nullptr) {}

        // Parameterized constructor.
        StringWithPointer(const char* s) 
        {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }

        // Copy constructor.
        StringWithPointer(const StringWithPointer& other) 
        {
            if (other.str) 
            {
                str = new char[strlen(other.str) + 1];
                strcpy(str, other.str);} 
            else {str = nullptr;}
        }

        // Assignment operator.
        StringWithPointer& operator=(const StringWithPointer& other) 
        {
            if (this == &other) 
            {
                return *this; // Self-assignment, no action needed.
            }

            // Deallocate the current memory (if any).
            delete[] str;

            if (other.str) {
                str = new char[strlen(other.str) + 1];
                strcpy(str, other.str);}
            else {str = nullptr;}

            return *this;
        }

        // Non-trivial destructor.
        ~StringWithPointer() 
        {
            delete[] str;
        }

        // Member function to display the string.
        void display() 
        {
            if (str) {cout << str << endl;}
            else {cout << "Empty string" << endl;}
        }
};

int main() {
    StringWithPointer s1("Hello, world!");
    StringWithPointer s2 = s1; // Copy constructor.
    StringWithPointer s3;
    s3 = s1; // Assignment operator.

    s1.display(); 
    s2.display(); 
    s3.display(); 

    // Destructor is called automatically when objects go out of scope at the end of "Main" function.
    return 0;
}
