# include<iostream>
# include<vector>
using namespace std;
/*
Polymorphism is the third essential feature of an object-oriented programming language, 
after encapsulation and inheritance. Late binding is used in order to implement Polymorphism.
For a function to behave polymorphically: use the "virtual" keyword + pointers or references 
to the base class.
*/

class Musician
{
    public:
        virtual void greet();   // Declaration of virtual greet function.
};

// Function Definition.
void Musician::greet() {cout << "Musician says: Hello\n";}

class Trumpeter: public Musician    // Derived from Musician class.
{
    public:
        virtual void greet();   // Declaration of virtual greet function.
};

// Function Definition.
void Trumpeter::greet() {cout << "Trumpeter says: Hello\n";} // Overrides greet() from Musician class.

class Pianist: public Musician      // Derived from Musician class.
{
    public:
        virtual void greet();   // Declaration of virtual greet function.
};

// Function Definition.
void Pianist::greet() {cout << "Pianist says: Hello\n";}  // Overrides greet() from Musician class.

// Polymorphic code only using pointers to the base class Musician.
void Musiciangreet(Musician* pm)   // Function that receives a parameter pointer to base class Musician.
{
    cout << "Introducing....\n";
    pm->greet();
    // This routine will work on an instance of Musician or any class derived from Musician because
    // greet() is virtual. Doing this means we don't have to write Musiciangreet() for each dericed
    // class. We can simply pass for eg. the address of Pianist in the function.
}
// Invoking virtual functions dynamically with reference.
void MusiciangreetingRef(Musician &rm)     // Using reference this time.
{rm.greet();}

int main()
{
    Trumpeter t;    // Trumpeter instance t.
    Pianist p;  // Pianist instance p.
    Musician m, *pm;    // Musician instance m and a Musician pointer *pm.

    // 1: Invoking through a Musician instance.
    m.greet();      // prints "Musician says: Hello".
    cout << "-------------------------------------------------------" << endl;

    // 2: Invoking through Trumpeter and Pianist instances.
    t.greet();      // prints "Trumpeter says: Hello".
    p.greet();      // prints "Pianist says: Hello"
    cout << "-------------------------------------------------------" << endl;

    // 3: Invoking through a Musician pointer on a Musician instance.
    pm = &m;    // pm points to Musician. Initialises pm with address of m.
    pm->greet();    // Prints "Musician says: Hello".
    cout << "-------------------------------------------------------" << endl;
    
    // 4: Invoking through a Musician pointer on a Trumpeter instance and on a Pianist instance.
    pm = &t;    // Points to Trumpeter. Upcasting.
    pm->greet();    // Prints "Trumpeter says: Hello".
    pm = &p;    // Points to Pianist. Upcasting.
    pm->greet();    // Prints "Pianist says: Hello".
    // Here both greet() would have printed "Musician says: Hello" if we didn't use "virtual" keyword.
    cout << "-------------------------------------------------------" << endl;

    vector<Musician*> orchestra; // Holds the entire orchestra which is a vector of pointer to Musician.
    orchestra.push_back(new Trumpeter);     // Adds Trumpeter to vector orchestra.
    orchestra.push_back(new Pianist);
    for (int i=0; i<orchestra.size(); i++)
        {Musiciangreet(orchestra[i]);}  // Calling Musiciangreet() on elements of orchestra vector.
    for (int i=0; i<orchestra.size(); i++)
        {delete orchestra[i];}    // Release memory to use later on.
    
    cout << "-------------------------------------------------------" << endl;    
    Musician m1;
    Trumpeter t1;
    Pianist p1;
    MusiciangreetingRef(m1); // Will result in invocation of Musician::greet().
    MusiciangreetingRef(t1); // Will result in invocation of Trumpeter::greet().
    MusiciangreetingRef(p1); // Will result in invocation of Pianist::greet().

    return 0;
}
