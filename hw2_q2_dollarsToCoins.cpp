// 
// sh7245_hw2_q2.cpp
// 
// Question 2:
/* Write a program that asks the user to enter an amount of money in the format of dollars
and remaining cents. The program should calculate and print the minimum number of coins
(quarters, dimes, nickels and pennies) that are equivalent to the given amount. */
//
#include <iostream>
using namespace std;

const int DOLLAR_CENT_VALUE = 100;
const int QUARTER_CENT_VALUE = 25;
const int DIME_CENT_VALUE = 10; 
const int NICKEL_CENT_VALUE = 5;

int main ()
{
    int dollars, cents, total_cents;
    int quarters, dimes, nickels, pennies;

    cout<<endl<<"Please enter your amount in the format of dollars and cents separated" 
        " by a space;"<<endl;
    cin>>dollars>>cents;

    total_cents = (dollars * 100) + cents;

    quarters = total_cents / QUARTER_CENT_VALUE;
    dimes = ((total_cents) - (quarters * QUARTER_CENT_VALUE)) / DIME_CENT_VALUE;
    nickels = ((total_cents) - (quarters * QUARTER_CENT_VALUE) - (dimes * DIME_CENT_VALUE))
         / NICKEL_CENT_VALUE;
    pennies = ((total_cents) - (quarters * QUARTER_CENT_VALUE) - (dimes * DIME_CENT_VALUE)
         - (nickels * NICKEL_CENT_VALUE));

    cout<<dollars<<" dollars and "<<cents<<" cents are:"<<endl<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels and "<<pennies<<" pennies"<<endl<<endl;

    return 0;

}