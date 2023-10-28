# include<iostream>
using namespace std;

int main()
{
    /* Constants must be declared and initialised at the same time.
       We need to use the keyword "const".
    */
    const double pi = 3.14;
    const int MountEverest = 8848;
    /*
        enum is a constants of type "int".
    */
    enum{Maths = 90, Economics, Physics};
    cout <<"Maths: " << Maths <<" Economics: "<< Economics <<" Physics: " << Physics;
    return 0;
} 