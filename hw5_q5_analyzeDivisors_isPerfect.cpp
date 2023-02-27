//
// sh7245_hw5_q5.cpp
//
// Question 5:
/* Write a program that reads from the user a positive  integer M (>=2),
prints all perfect numbers and all amicable numbers between 2 and M.  */
//
#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
/* Takes a positive integer represented by "int num" (>=2), and updates
two output paramters with the number of num's proper divisors (represented 
by "outCountDivs") and their sum (represented by "outSumDivs") */

bool isPerfect(int num);
/* Takes a positive integer represented by "int num" (>=2) and returns
"true" if num is a perfect number, or "false" if it is not. */

int main ()
{
    int m, current_num;

    cout<<endl<<"Please enter a positive integer >=2: ";
    cin>>m;

    cout<<endl<<"The perfect numbers between 2 and "<<m<<" are:"<<endl;
    for (current_num = 2; current_num <= m; current_num++)
    {
        if (isPerfect(current_num) == true)
            cout<<current_num<<" ";
    }
    cout<<endl;

    cout<<endl<<"The pairs of amicable numbers between 2 and "<<m<<" are:"<<endl;
    
    int n1, count, sum_1, sum_2;
    for (n1 = 2; n1 <= m; n1++)
    {
        analyzeDividors (n1, count, sum_1);
        if ((sum_1 > n1) && (sum_1 <= m))
        {
            analyzeDividors(sum_1, count, sum_2);
            if (sum_2 == n1)
                cout<<n1<<" "<<sum_1<<endl;
        }
    }
    cout<<endl;

    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{
    double sqrt_num; 
    int k_div, d_div;
    sqrt_num = sqrt(num);
    outCountDivs = 1;
    outSumDivs = 1;
    for (k_div = 2; k_div < sqrt_num; k_div++)
    {
        if (num % k_div == 0)
        {
            outCountDivs++;
            outSumDivs += k_div;
        }
    }
    for (k_div = sqrt_num; k_div >= 2; k_div--)
    {
        if ((num % k_div == 0))
        {
            d_div = num / k_div;
            outCountDivs++;
            outSumDivs += d_div;
        }
    }
}

bool isPerfect(int num) 
{
    int Count_Divs, Sum_Divs;
    analyzeDividors(num, Count_Divs, Sum_Divs);
    if (Sum_Divs == num)
        return true;
    else
        return false;
}
