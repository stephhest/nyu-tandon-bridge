//
// sh7245_hw6_q5
//
// Question 5:
/* Write a program that reads a person’s name in the following format: 
first name, then middle name or initial, and then last name.
The program then outputs the name in the following format:  
Last_Name, First_Name Middle_Initial. */
//
#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string first, middle, last, mid_in;

    cout<<endl;
    cout<<"Enter your first name, middle name or inital, "
    "and last name, each separated by a space: "<<endl;
    cin>>first>>middle>>last;
    cout<<endl;

    mid_in = middle[0];

    cout<<"Output: ";
    cout<<last<<", "<<first<<" "<<mid_in<<"."<<endl;
    cout<<endl;

    return 0;
}
