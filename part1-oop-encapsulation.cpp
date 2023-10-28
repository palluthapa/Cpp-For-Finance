# include<iostream>
using namespace std;

/*The idea of hiding data using private keyword is often called encapsulation. This concept 
refers to combining a number of items such as variables and functions into a single package, 
such as an object of some class and preventing direct messing with the internal data of an object.*/

class Day
{   public:
        void output();
        void set(int new_year, int new_month, int new_date);    // Accessor Function.
        void input();
        int get_year();
        int get_month();
        int get_day();
    private: 
        void check_date();
        int year;
        int month;
        int day;    };

int main()
{
   Day today, yesterday;   // creating objects of class Day.
   today.input();
   yesterday.set(2023,8,8);
   cout << today.get_month() << endl;
   yesterday.output();
   return 0;
} 

// Member Function Definitions.
void Day::input() 
{
    cout << "Enter the year: " << endl; cin >> year;
    cout << "Enter the month: " << endl; cin >> month;
    cout << "Enter the day: " << endl; cin >> day;
    check_date();   // Private function used inside public function and not used by user directly.
}

void Day::check_date()
{ 
    if ((year < 1) || (year > 2023)||(month < 1) ||(month > 12) || (day < 1) || (day > 31))
        {cout << "Illegal date. Aborting program.\n";
        exit(1);}
}

int Day::get_year()
{ return year;}

int Day::get_month()
{ return month;}

int Day::get_day()
{ return day;}

void Day::output()
{cout << "year = " << year << " month = "<< month << " day = " << day << endl;}

void Day::set(int new_year, int new_month, int new_date)
{
    year = new_year;
    month = new_month;
    day = new_date; 
    check_date();
}