# include<iostream>
# include <string.h>
using namespace std;

// Strings in C++ are 1-D array of characters which are terminated by null character "\0"

// stringLength() function to compute length of a string.
int stringLength(char * S)    // S represents pointer to first element of string.
{ 
    int length = 0;
    while ((*S)!= '\0')    // Continue looping until we reach last null terminating character '\0'.
    {
        S++;    // Next element of string.
        length++;
    }
    return length;
}

int main()
{
    char greeting[3] = {'h' , 'i', '\0'}; // Creating a String.
    char bark[] = "Woof, Woof"; // Another way to create String.
    cout << greeting << " " << bark << endl;

    char str1[10] = "Hello";
    char str2[10] = "World";
    char str3[10];
    int len;
    strcpy(str3,str1);  // copy str1 into str3.
    cout << "strcpy(str3, str1): " << str3 << endl;
    strcat(str1, str2); // concatenate str2 onto the end of string str1.
    cout << "strcat(str1,str2): " << str1 << endl;
    len = strlen(str1);   // total length of str1 after concatenation.
    cout << "strlen(str1): " << len <<endl;
    cout << str1 << endl;

    // Calling stringLength() function.
    cout << "stringLength(str2): " << stringLength(str2) << endl;

    return 0;
}