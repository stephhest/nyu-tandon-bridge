//
// sh7245_hw8_q1.cpp
//
// Question 1:
/* Give a recursive implement to the following functions. */
//
#include <iostream>
using namespace std;

void printTriangle(int n);
/* When given a positive integer (n), prints a textual image 
of a right triangle aligned left with n lines. */

void printOppositeTriangles(int n);
/* When given a positive integer (n), prints a textual image
of two opposite right triangles aligned left, each with n lines. */

void printRuler(int n);
/* When given a positive integer (n), prints a vertical ruler
of 2^n-1 lines. Each line contains either n, n-1, n-2, or 1 marks. */

int main ()
{
    int n = 4;

    printTriangle(n);
    cout<<endl;

    printOppositeTriangles(n);
    cout<<endl;

    printRuler(n);
    cout<<endl;

    return 0;
}

void printTriangle(int n)
{
    if (n == 0)
        return;
    else
        printTriangle(n-1);
    for (int i=0; i<n; i++)
        cout<<"* ";
    cout<<endl;

}

void printOppositeTriangles(int n)
{
    for (int i=0; i<n; i++)
        cout<<"* ";
    cout<<endl;
    if (n-1 > 0)
        printOppositeTriangles(n-1);
    for (int i=0; i<n; i++)
        cout<<"* ";
    cout<<endl;
}

void printRuler(int n)
{
    if (n-1 > 0)
        printRuler(n-1);
    for (int i=0; i<n; i++)
        cout<<"-";
    cout<<endl;
    if (n-1 > 0)
        printRuler(n-1);
}