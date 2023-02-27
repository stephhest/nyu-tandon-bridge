// 
// sh7245_hw2_q1.cpp
// 
// Question 1:
/* Write a program that asks the user to enter a number of quarters, dimes, nickels and pennies 
and then outputs the monetary value of the coins in the format of dollars and remaining cents. */
//
#include <iostream>
using namespace std;

const int DOLLAR_CENT_VALUE = 100;
const int QUARTER_CENT_VALUE = 25;
const int DIME_CENT_VALUE = 10; 
const int NICKEL_CENT_VALUE = 5;

int main () 
{
int quarters, dimes, nickels, pennies;
int total_cents, dollars, remaining_cents;

cout<<endl<<"Please enter number of coins:"<<endl;
cout<<"# of quarters: ";
cin>>quarters;
cout<<"# of dimes: ";
cin>>dimes;
cout<<"# of nickels: ";
cin>>nickels;
cout<<"# of pennies: ";
cin>>pennies;

total_cents = (quarters * QUARTER_CENT_VALUE) + (dimes * DIME_CENT_VALUE) + 
    (nickels * NICKEL_CENT_VALUE) + (pennies);

dollars = total_cents / DOLLAR_CENT_VALUE;
remaining_cents = total_cents % DOLLAR_CENT_VALUE;

cout<<endl<<"The total is "<<dollars<<" dollars and "<<remaining_cents<<" cents"<<endl<<endl;

return 0;

}
