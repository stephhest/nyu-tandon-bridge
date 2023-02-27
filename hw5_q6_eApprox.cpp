//
// sh7245_hw5_q6.cpp
//
// Question 6:
/* Implement a function that when given a positive integer n, it
returns an approximation of e, calculated by the sum of the first
(n+1) addends of the infinite series of e. */
//
#include <iostream>
#include <cmath>
using namespace std;

int factorial (int num);
/* Takes a positive integer n and returns the value of n! */

double eApprox(int n);
/* Takes a positive integer n and returns an approximation of e. */

int main ()
{
    cout.precision(30);

    for (int n = 1; n <= 15; n++) 
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;

    return 0;
}

int factorial (int num) 
{
    int count;
    double fact_num;
    fact_num = 1.0;
    for (count = 1; count <= num; count++)
        fact_num *= count;
    return fact_num;
}

double eApprox(int n)
{
    int count;
    double fact_num, current_addend, e_approx;
    e_approx = 1.0;
    for (count = 1; count <= n; count++)
    {
        fact_num = factorial(count);
        current_addend = (1/fact_num);
        e_approx += current_addend;
    }
    return e_approx;
}