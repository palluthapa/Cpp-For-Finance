/* Using Class Vector from the C++ Standard Library. Some useful functions of the class Vector are:
push_back // add element at the end.
size() // return size.
resize() // change size.
operator [] // access element.
*/
# include<iostream>
using namespace std;
# include <vector>

double sum( const vector<double>& v );  // Vector Summing Function.
/* Rule: Use const and & symbols. We need to pass the vector by reference because vectors
are too big to keep copying all the time.
*/

int main()
{
    // Create a vector myVector.
    vector<double> myVector;
    // Add three elements to the end.
    myVector.push_back( 12.0 );
    myVector.push_back( 13.0 );
    myVector.push_back( 14.0 );
    // Read the first, second and third elements.
    cout << myVector[0] <<"\n";
    cout << myVector[1] <<"\n";
    cout << myVector[2] <<"\n";
    // Change the values of a vector.
    myVector[0] = 0.1;
    myVector[1] = 0.2;
    myVector[2] = 0.3;
    // Loop through a vector.
    int n = myVector.size();
    for (int i=0; i<n; i++) 
    {
        cout << myVector[i] <<",";
    }
    cout << endl;
    // Create a vector of length 7 consisting entirely of 2.0’s.
    vector<double> seven2s(7, 2.0 );
    n = seven2s.size();
    for (int i=0; i<n; i++) 
    {
        cout << seven2s[i] <<",";
    }
    cout << endl;
    // Create a vector which is a copy of another.
    vector<double> copy( seven2s );
    // replace it with myVector.
    copy = myVector;
    n = copy.size();
    for (int i=0; i<n; i++) 
    {
        cout << copy[i] <<",";
    }
    cout << endl;
    // The function size gives the number of elements.
    cout << seven2s.size() << endl;
    myVector.resize(5); // resize the vector. At this point,the vector contains 0.1, 0.2, 0.3, 0,0.
    myVector.resize(2); // resize the vector. At this point, the vector contains 0.1, 0.2.
    n = myVector.size();
    for (int i=0; i<n; i++) 
    {
        cout << myVector[i] <<",";
    }
    cout << endl;
    cout << sum(seven2s) << endl;
    return 0;
} 

double sum( const vector<double>& v ) 
{
    double total = 0.0;
    int n = v.size();
    for (int i=0; i<n; i++) 
    {
        total += v[i];
    }
    return total;
}