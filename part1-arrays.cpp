# include<iostream>
using namespace std;

/* sumArray function receives array and its length as parameter and returns sum
   of all elements of array. */
int sumArray( int array[], int length ) 
{
    int sum = 0;
    for (int i = 0; i < length; i++) 
        {
            sum += array[i];
        }
    return sum;
}

/* sumUsingPointer function is another way to pass an array as parameter to function
   using pointer.*/
int sumUsingPointer( int* array, int length ) 
{
    int sum = 0;
    for (int i = 0; i < length; i++) 
        {
            sum += array[i];
        }
    return sum;
}

int main()
{
    int Array1[3];  // Array1 is uninitialised array of length 3.
    int Array2[] = {1,2,3};  // Initialised array with 3 elements [1,2,3].
    int Array3[3] = {0};    // Array3 = [0,0,0].
    int Array4[5] = {5,6,7};    // Array4 = [5,6,7,0,0].
    cout << Array4[2] << endl;   // Third element of array.
    cout << *(Array4 + 2) << endl;  // Accessing third element via Pointers.


    // Calling sumArray() function.
    cout << "sumArray(Array2,3): " << sumArray(Array2,3) << endl;

    // Calling sumUsingPointer() function.
    cout << "sumUsingPointer(Array2,3): " << sumUsingPointer(Array2,3) << endl;

    // Multi-Dimensional Array.
    int Array5[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};  // Creates 3x3 array. [rows no] [col no].
    for (int i=0; i<3; i++)     // i = row index.
    {
        for (int j=0; j<3; j++)     // j = column index. 
        {
            cout<<"Entry ("<<i<<","<<j<<")= " << Array5[i][j] << endl;
        }
    }

    return 0;
}