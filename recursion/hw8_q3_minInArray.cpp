//
// sh7245_hw8_q3.cpp
//
// Question 3:
/* Write two recursive versions of the function minInArray. 
Each function will be given a sequence of elements and should return 
the minimum value in the sequence. The functions differ from one
another in the technique used to pass the sequence to the function. */
//
#include <iostream>
using namespace std;

int minInArray1(int arr[], int arrSize);
/* When given array of integers (arr) and its logical size (arrSize),
function returns the minimum value out of all elmements in array. */

int minInArray2(int arr[], int low, int high);
/* When given array of integers (arr), lowest index and highest index,
function returns the minimum value out of all elmements in array. */

int main ()
{
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);

    cout<<endl;
    cout<<"Res1 and Res2: "<<endl;
    cout<<res1<<", "<<res2<<endl;
    cout<<endl;

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4);

    cout<<"Res3 and Res4: "<<endl;
    cout<<res3<<", "<<res4<<endl;
    cout<<endl;

    return 0;
}

int minInArray1(int arr[], int arrSize)
{
    if (arrSize == 0)
        return 0;
    else if (arrSize == 1)
        return arr[0];
    else
    { 
        int min;
        min = minInArray1(arr, arrSize-1);
        if(arr[arrSize-1] < min)
            min = arr[arrSize-1];
        return min;
    }
}

int minInArray2(int arr[], int low, int high)
{
    int arrSize = (high-low)+1;
    if (arrSize == 0)
        return 0;
    else if (arrSize == 1)
        return arr[low];
    else
    { 
        int min;
        min = minInArray2(arr, low+1, high);
        if(arr[low] < min)
            min = arr[low];
        return min;
    }
}