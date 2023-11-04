# include<iostream>
# include <cassert> // For release version of software disable assertion by "# define NDEBUG".
using namespace std;

/*
Inheritance is the 2nd main concept in OOP after encapsulation/abstraction.
To avoid repeating common member functions and member variables, we will create a class hierarchy, where
the common member functions and variables are placed in a base class and specialized ones are placed
in derived classes.
In the example below We have a single base(Parent) class "Account" which has two derived(child) classes
"SavingsAccount" and "CheckingAccount". From "SavingsAccount", we have another derived class "TimeAccount".
*/

class Account   // Base(Parent) Class.
{
    protected:
        double balance; // Account balance is not publicly accessible outside the class, but it is
                        // accesible in the derived classes as it is protected.
    public:
        Account(): balance(0.0){};    // Default Constructor sets balance to zero.
        Account(double bal): balance(bal){};    // Constructor with parameter.
        void deposit(double amt){balance+=amt;} // Deposit Function.
        double get_balance() const {return balance;}    // Accessor Function (getters).
};

class SavingsAccount: public Account    // Derived Class from Account class.
{
    protected:
        double rate; // Periodic interest rate. Specific member variable to SavingsAccount child class.
    public:
        SavingsAccount(): Account(){rate=0.0;}; // Default Constructor sets balance and rate to zero.
        // Constructor with parameter.
        SavingsAccount(double bal, double rate): Account(bal){this->rate=rate;};
        double compound() // Compound function specific to this class.
        {
            double interest = balance*rate; // Computes interest
            balance += interest;    // Increases balance by interest.
            return interest;
        }
        double withdraw(double amt) 
        {// If overdraft return 0, else return amount.
            if (amt > balance) { return 0.0;}   // Overdraft case.
            else
            {
                balance-=amt;   // Balance updated after withdrawing money.
                return amt;
            }
        }
};

class CheckingAccount: public Account   // Derived Class from Account class.
{
    protected:
        double limit;   // Lower limit for free checking.
        double charge;  // Per check charge.
    public:
        CheckingAccount(): Account(){limit = 0; charge = 0;};   // Default Constructor.
        CheckingAccount(double bal, double lim, double chg): Account(bal), limit(lim),\
        charge(chg){};  // Constructor with parameter.
        // Function that allows us to withdraw cash using check from CheckingAccount.
        double cash_check(double amt)
        {
            assert(amt > 0);  // Assert function used to validate parameter.
            if (balance < limit && (amt+charge <= balance))
            {
                balance -= amt+charge;  // Balance updated after withdrawing money with charge.
                return amt;
            }
            else if (balance >= limit && amt <= balance)
            {
                balance -= amt;     // Balance updated after withdrawing money, No charge.
                return amt;
            } 
            else {return 0.0;}  // If both cases not satisfied we return 0.
        }
};

class TimeAccount: public SavingsAccount    // Derived Class from SavingsAccount class.
{
    protected:
        double funds_avail; // Amount available for withdrawal. A protected member variable.
    public:
        TimeAccount(): SavingsAccount(){funds_avail = 0.0;};    // Default Constructor.
        // Constructor with parameter.
        TimeAccount(double bal, double rate): SavingsAccount(bal, rate), funds_avail(0.0){};
        // Redefining member functions "compound()" and "withdraw()" from SavingsAccount.
        double compound()
        {
            double interest = SavingsAccount::compound(); // Member variable "interest" equals value
                                // returned by the compound() function from parent class SavingsAccount.
            funds_avail += interest;  // Specific member variable of TimeAccount class "funds_avail" 
                                      // increases by the interest.
            return interest;
        }
        double withdraw(double amt)
        {
            if (amt <= funds_avail)
            {
                funds_avail -= amt;
                balance -= amt;
                return amt;
            } 
            else { return 0.0;}
        }
        double get_avail() const    // Accessor Function specific to TimeAccount class (getters).
        {return funds_avail;}
};

int main()
{
    // Overriding Members.
    TimeAccount obj;    // Defines object of TimeAccount class.
    cout << obj.compound() << endl; // Calls the function compound defined in the class TimeAccount.
    cout << obj.SavingsAccount::compound(); // Calls compound defined in the class SavingsAccount.
    return 0;
}