//
// sh7245_hw2_q4.cpp
//
// Question 4:
/* Write a program that reads from the user two positive integers, and prints the result 
of when we add, subtract multiply, divide, div and mod them. */
//
#include <iostream>
using namespace std;

int main ()
{
    int n1, n2, sum, difference, product, div, mod;
    double quotient;
    
    cout<<endl<<"Please enter two positive integers, separated by a space:"<<endl;
    cin>>n1>>n2;

    sum = n1 + n2;
    difference = n1 - n2;
    product = n1 * n2;
    quotient = (double)n1 / (double)n2;
    div = n1 / n2;
    mod = n1 % n2;

    cout<<n1<<" + "<<n2<<" = "<<sum<<endl;
    cout<<n1<<" - "<<n2<<" = "<<difference<<endl;
    cout<<n1<<" * "<<n2<<" = "<<product<<endl;
    cout<<n1<<" / "<<n2<<" = "<<quotient<<endl; 
    cout<<n1<<" div "<<n2<<" = "<<div<<endl;
    cout<<n1<<" mod "<<n2<<" = "<<mod<<endl<<endl;

    return 0;

}