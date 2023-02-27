//
// sh7245_hw5_q1.cpp
//
// Question 1:
/* Write a function int fib(int n) that returns the nth element
of the Fibonacci sequence. Write a  program that prompts the 
user to enter a positive integer num, and then prints the num's
elements in the Fibonacci sequence. */
//
#include <iostream>
using namespace std;

int fib(int n);
// Returns the n-th element of the Fibonacci sequence,
// where the formal parameter "n" is a positive integer.

int main () 
{
    int num, nth_element;

    cout<<endl<<"Please enter a positive integer: ";
    cin>>num;

    nth_element = fib(num);

    cout<<nth_element<<endl;

    return 0;
}
int fib(int n)
{
    int count, first_digit, last_digit, sum;
    sum = 0;
    first_digit = 0;
    last_digit = 1;
    for (count = 1; count < n; count++)
    {
        sum = first_digit + last_digit;
        first_digit = last_digit;
        last_digit = sum;     
    }
    return last_digit;
}