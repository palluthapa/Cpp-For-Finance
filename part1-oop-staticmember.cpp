# include<iostream>
using namespace std;

/*Static member variables and static functions are associated with the class,
not with the instance. Static variables has same value in any instance of the
class. We can use static member variable to keep track of no. of different 
instances/objects that has been created from a class.
The following program uses static variables and static functions to give 
each instance of a class a unique id. */

class user
{   private:
        int id;
        static int next_id;     // Static variable next_id.
    public:
        int get_id();   // Accessor Function.
        user();  // constructor.
        static int next_user_id()   // Static member function.
        {   
            next_id++;
            return next_id;
        }
};

int user::next_id = 0;  // Initialising static member variable. Notice the calling syntax.

// Constructor definition.
user::user()
{
    id = user::next_id++; // or
    // id = user::next_user_id();
}

// Class Methods Definition.
int user::get_id()
{ return id;}

int main()
{
    user user1;   // Default Constructor is invoked while creating this object.
    cout << "ID: " << user1.get_id() << endl;
    user user2;
    cout << "ID: " << user2.get_id() << endl;
    return 0;
}
