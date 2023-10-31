# include<iostream>
using namespace std;

/*Constructors are used to initialize objects and are called automatically when
an object is declared. A constructor must have the same name as the class and its
definition cannot return a value. No return type, no void.
A Class might have several types of constructors so the constructor can be overloaded.*/

class BankAccount
{   public:
        BankAccount (int pound, int pence, double rate);  // Constructor with parameter.
        BankAccount();  // Default Constructor that initialise attributes with default values.
        double get_balance();   // Accessor Function.
        double get_rate();
        void output(); 
    private:    // Attributes are set Private.
        double balance;
        double interest_rate;
};

int main()
{
    BankAccount account1(787, 50, 7); // Construcrtor with parameter is invoked creating this object.
    BankAccount account2;   // Default Constructor is invoked while creating this object.
    account1.output();
    account2.output();
    account1.get_balance();
    account1.get_rate();
    return 0;
}

// Constructor with parameter definition.
BankAccount::BankAccount(int pound , int pence, double rate)
{ 
    if((pound < 0) || (pence < 0) || (rate<0))
        { cout<<"Illegal values for money or interest rate. \n"; exit(1);}
    (*this).balance = pound + (0.01 * pence);   // (*this).balance is same as balance.
    (*this).interest_rate = rate;  // *this is a pointer to invoking object of the class.
    // *this pointer is used for (1) overloading operators & (2) when method parameters have same
    // names as attribute names.
}

// Default Constructor definition.
BankAccount::BankAccount(): balance(0), interest_rate(0) {}
// Alternatively, BankAccount::BankAccount() {balance = 0; interest_rate = 0;}

// Class Methods Definition.
double BankAccount::get_balance()
{ return balance;}

double BankAccount::get_rate()
{return interest_rate;}

void BankAccount::output()
{cout << "Account Balance = " << balance << " pound sterling & Interest Rate = "<< interest_rate \
<< "%" << endl;}
