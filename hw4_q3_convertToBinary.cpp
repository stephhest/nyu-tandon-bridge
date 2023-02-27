//
// sh7245_hw4_q3.cpp
//
/*  Write a program that reads from the user a positive integer (in a 
decimal representation), and prints its binary (base 2) representation. */
//
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int original_decimal, current_decimal, binary_number, counter;

    cout<<endl<<"Enter decimal number:"<<endl;
    cin>>original_decimal;

    binary_number = 0;
    counter = 0;
    current_decimal = original_decimal;
    while (current_decimal > 0)
    {
        if  (current_decimal % 2 == 1)
            binary_number += (pow(10, counter));
        current_decimal /= 2;
        counter++;
    }

    cout<<"The binary representation of "<<original_decimal<<" is "
    <<binary_number<<endl<<endl;
    
    return 0;
}