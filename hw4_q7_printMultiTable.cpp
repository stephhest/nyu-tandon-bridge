//
// sh7245_hw4_q7.cpp
//
/*  Write a program that reads a positive integer n from the user and 
prints out a nxn multiplication table. The columns should be spaced by a tab. */
//
#include <iostream>
using namespace std;

int main ()
{
    int n, line_count, digit_count, curr_digit;
    cout<<"Please enter a positive integer: "<<endl;
    cin>>n;

    for (line_count = 1; line_count <= n; line_count++)
    {
        curr_digit = line_count;
        for (digit_count = 1; digit_count <= n; digit_count++)
        {
            cout<<curr_digit<<"\t";
            curr_digit += line_count;
        }
        cout<<endl;
    }
    return 0;
}