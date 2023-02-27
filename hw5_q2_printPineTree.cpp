//
// sh7245_hw5_q2.cpp
//
// Question 2:
/* Write a program that prints a 'pine tree' consisting of 
triangles of increasing sizes, filled with a character. The 
program should read from a user the number of triangles
and the character filling the tree. */
//
#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
/* Prints a n-line triangle, filled with symbol characters,
shifted m spaces from the left margin. */

void printPineTree(int triangles, char symbol);
/* Prints a sequence of triangles of increasing sizes, which  
form the shape of a pine tree, filled with symbol characters. */

int main ()
{
    int n;
    char symbol;

    cout<<"Please enter a positive integer: ";
    cin>>n;
    cout<<"Please enter a character symbol: ";
    cin>>symbol;

    printPineTree(n, symbol);
    
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol)
{
    int line_count, margin_count, space_count, sym_count;    
    for (line_count = 1; line_count <= n; line_count++)
    {
        for (margin_count = 1; margin_count <= m; margin_count++)
            cout<<" ";
        for (space_count = 1; space_count <=(n-line_count);
        space_count++)
            cout<<" ";
        for (sym_count = 1; sym_count <= (2*line_count)-1; 
        sym_count++)
            cout<<symbol;
        cout<<endl;
    }    
}
void printPineTree(int n, char symbol)
{
    int tri_count, rows, margin;
    for (tri_count = 1; tri_count <= n; tri_count++)
    {
        rows = tri_count + 1;
        margin = n - tri_count;
        printShiftedTriangle(rows, margin, symbol);
    }
}