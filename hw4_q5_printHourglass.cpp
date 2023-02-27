//
// sh7245_hw4_q5.cpp
//
/*  Write a program that asks the user to input a positive integer n, and prints 
a textual image of an hourglass made of 2n lines with asterisks. */
//
#include <iostream>
using namespace std;

int main () 
{
    int n;
    int line_count, star_count, space_count;

    cout<<endl<<"Please enter a positive integer: ";
    cin>>n;

    for(line_count = n; line_count >= 1; line_count--)
    {
        for(space_count = 1; space_count <= (n - line_count); space_count++)
            cout<<" ";

        for(star_count = 1; star_count <= ((2*line_count) - 1); star_count++)
            cout<<"*";

        cout<<endl;
    }

    for(line_count = 1; line_count <= n; line_count++)
    {
        for(space_count = 1; space_count <= (n - line_count); space_count++)
            cout<<" ";

        for(star_count = 1; star_count <= ((2*line_count) - 1); star_count++)
            cout<<"*";

        cout<<endl;
    }

    return 0;
}