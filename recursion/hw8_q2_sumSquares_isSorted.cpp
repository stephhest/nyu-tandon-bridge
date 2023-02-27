//
// sh7245_hw8_q2.cpp
//
// Question 2:
/* Give a recursive implement to the following functions. */
//
#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);

bool isSorted(int arr[], int arrSize);

int main ()
{
    const int arrSize = 4;
    int arr[arrSize] = {2, -1, 3, 10};

    cout<<endl;
    cout<<"Sum of Squares: ";
    cout<< sumOfSquares(arr, arrSize);

    cout<<endl;
    cout<<"Is array sorted? ";
    if (isSorted(arr, arrSize) == true)
        cout<<"Yes!"<<endl;
    else
        cout<<"No."<<endl;
    cout<<endl;
    
    return 0;
}

int sumOfSquares(int arr[], int arrSize)
{
    int last_index = arrSize - 1;
    int sum;

    if (arrSize == 0)
        return 0;
    else
        sum = (arr[last_index] * arr[last_index]) + sumOfSquares(arr, last_index);
        return sum;
}

bool isSorted(int arr[], int arrSize)
{
    int last_index = arrSize - 1;

    if (arrSize == 0 || arrSize == 1)
        return true;
    else
    {
        if (arr[last_index] < arr[last_index-1])
            return false;
        else   
            return isSorted(arr, arrSize-1);
    }

}