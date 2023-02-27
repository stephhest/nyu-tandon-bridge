//
// sh7245_hw4_q1.cpp
//
/* Write two versions of a program that reads a positive integer n, 
and prints the first n even numbers.
a) In the first, use a while loop.
b) In the second, use a for loop. */
//
#include <iostream>
using namespace std;

int main ()
{
    int n;
    int counter;
    int current_even_number;

    cout<<endl<<"Please enter a positive integer: ";
    cin>>n;

    cout<<endl<<"Section A"<<endl;
    counter = 0;
    current_even_number = 0;
    while (counter < n)
    {
        current_even_number += 2;
        cout<<current_even_number<<endl;
        counter++; 
    }

    cout<<endl<<"Section B"<<endl;
    current_even_number = 0;
    for (counter = 0; counter < n; counter++)
    {
        current_even_number += 2;
        cout<<current_even_number<<endl;
    }
    
    
    return 0;
}