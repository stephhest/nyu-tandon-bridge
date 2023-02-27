//
// sh7245_hw5_q4.cpp
//
// Question 4:
/* Write a program that reads from the user a positive
integer (>=2), and prints all of its divisors. */
//
#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);
/* Takes a positive integer >= 2, represented by "int num",
and prints all of num's divisors in an ascending order. */

int main ()
{
    int n;

    cout<<endl<<"Please enter a positive integer >=2: ";
    cin>>n;

    printDivisors(n);
    cout<<endl<<endl;

    return 0;
}

void printDivisors(int num)
{
    double sqrt_num; 
    int k_div, d_div;
    sqrt_num = sqrt(num);
    for (k_div = 1; k_div < sqrt_num; k_div++)
    {
        if (num % k_div == 0)
            cout<<k_div<<" ";
    }
    for (k_div = sqrt_num; k_div >= 1; k_div--)
    {
        if (num % k_div == 0)
        {
            d_div = num / k_div;
            cout<<d_div<<" ";
        }
    }
}
