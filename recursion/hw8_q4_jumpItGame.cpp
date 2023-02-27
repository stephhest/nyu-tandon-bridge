//
// sh7245_hw8_q4.cpp
//
// Question 4:
/* Write a recursive function that returns the lowest cost of a
game board passed and represented as an array (see pdf for details). */
//
#include <iostream>
using namespace std;

int lowestGameCost (int arr[], int start, int end);
/* When given an array of positive integers (arr), which represent
the values of columns of a game board in order, function returns the
lowest total cost of getting to the end per the rules of the game. */

int main ()
{
    // Modify game paramerters here only
    const int arrSize = 6;
    int arr[arrSize] = {0, 3, 80, 6, 57, 10};
    //

    int start = 0;
    int end = arrSize-1;
    int cost = 0;

    cost = lowestGameCost(arr, start, end);

    cout<<endl;
    cout<<"Lowest Game Cost: ";
    cout<<cost<<endl;
    
    return 0;
}

int lowestGameCost(int arr[], int start, int end)
{
    int cost = 0;
    if (start == end)
        return arr[0];
    else if (start+1 == end)
        return arr[end];
    else if (arr[start+1] < arr[start+2])
        cost += arr[start+1] + lowestGameCost(arr, start+1, end);
    else
        cost += arr[start+2] + lowestGameCost(arr, start+2, end);
    
    return cost;
}