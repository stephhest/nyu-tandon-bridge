//
// sh7245_hw4_q6.cpp
//
/* Write a program that asks the user to input a positive integer n, and prints 
all of the numbers from 1 to n that have more even digits than odd digits. */
//
#include <iostream>
using namespace std;

int main ()
{
    int n, current_int, current_num, even_digits, odd_digits;

    cout<<"Please enter a positive integer: ";
    cin>>n;

    for (current_int = 1; current_int <= n; current_int++)
    {
        even_digits = 0;
        odd_digits = 0; 
        current_num = current_int;

        while (current_num > 0)
        {
            if (current_num % 2 == 0)
                even_digits++;
            else
                odd_digits++;
            current_num /= 10;
        }

        if (even_digits > odd_digits)
            cout<<current_int<<endl;
    }

    return 0;

}

