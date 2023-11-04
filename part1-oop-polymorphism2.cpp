# include<iostream>
using namespace std;
/*
Constructors can not be virtual. The destructor of a class that you intend to use as a base class
should be a virtual destructor.
*/

// 1 Non-virtual Destructor.
class Base1     // Parent/base class.
{
    public:
        ~Base1(){ cout << "~Base1()\n ";}   // Destructor.
};
class Derived1: public Base1    // Child/Derived class.
{
    public: 
        ~Derived1(){cout << "~Derived1()\n";}   // Destructor.
};
// 2 Virtual Destructor.
class Base2     // Parent/base class.
{
    public:
        virtual ~Base2(){ cout << "~Base2()\n ";}   // Destructor.
};
class Derived2: public Base2    // Child/Derived class.
{
    public: 
    ~Derived2(){cout << "~Derived2()\n";}     // Destructor.
};

// Behavior of virtual vs. non-virtual destructor.
int main()
{
Base1 *bp = new Derived1; // Upcast version 1.
delete bp;      // Only calls base class destructor.
Base2 * bp2 = new Derived2; // Upcast version 2.
delete bp2;     // Calls the derived-class destructor followed by the base class destructor, which
                // is the behavior we desire, otherwise we will lose some memory.
}

/*
Note: Forgetting to make a destructor virtual is an insidious bug because it often 
doesn’t directly affect the behavior of your program, but it can quietly introduce a memory leak.
*/