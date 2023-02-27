//
// sh7245_hw4_q2.cpp
//
/* Write a program that reads from the user a (decimal) number, and prints 
it’s representation in the simplified Roman numerals system. */
//
#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int decimal_number, current_number;

    cout<<endl<<"Enter decimal number:"<<endl;
    cin>>decimal_number;

    cout<<decimal_number<<" is ";

    current_number = decimal_number;

    while ((current_number / 1000) != 0)
    {
        cout<<"M";
        current_number -= 1000;
    }

    while ((current_number / 500) != 0)
    {
        cout<<"D";
        current_number -= 500;
    }

    while ((current_number / 100) != 0)
    {
        cout<<"C";
        current_number -= 100;
    }
    
    while ((current_number / 50) != 0)
    {
        cout<<"L";
        current_number -= 50;
    }    

    while ((current_number / 10) != 0)
    {
        cout<<"X";
        current_number -= 10;
    }

    while ((current_number / 5) != 0)
    {
        cout<<"V";
        current_number -= 5;
    }

    while (current_number != 0)
    {
        cout<<"I";
        current_number -= 1;
    }

    cout<<endl;

    return 0;
}