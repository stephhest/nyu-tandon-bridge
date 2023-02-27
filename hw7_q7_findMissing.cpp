//
// sh7245_hw7_q7.cpp
//
// Question 7:
/* Implement a function that gets an array of integers of size n, containing
integers from range 0 to n. When called it should create a new array that 
contains the integer(s) in the range that is/are not in arr, and also update  
the output parameter with the logical size of the new array. */
//
#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
/* Takes an array (arr) of size (n), as well as an output int variable
(resArrSize). Function returns a new array containing any integer from 
the range 0-n that is missing from the original array, and updates the 
output parameter with the logical size of the new array. */

// MAIN TEST
int main ()
{
    const int ARR_SIZE = 6;
    int myArr[ARR_SIZE] = {3, 1, 3, 0, 6, 4};

    int n = ARR_SIZE;
    int resArrSize = 0;

    int range = n+1;
    int* missingNums = new int[range];

    missingNums = findMissing(myArr, n, resArrSize);

    cout<<endl;
    cout<<"Missing Nums Count: "<<resArrSize<<endl;
    cout<<"Missing Nums Array: ";
    for (int i=0; i<resArrSize; i++)
        cout<<missingNums[i]<<" ";
    cout<<endl;

    delete[]missingNums;

    return 0;
}

// FIND MISSING FUNCTION
int* findMissing(int arr[], int n, int& resArrSize)
{
    int range = n+1;
    int missingCount = 0;

    int* missingNums = new int[range];

    int i = 0;
    while (i < range) 
    {   
        bool isFound = false;
        int j = 0;
        while ((isFound == false) && (j < n))
        {
            if (i == arr[j])
                isFound = true;
            else
                j++;
        }
        if (isFound == false)
        {
            missingNums[missingCount] = i;
            missingCount++;
        }
        i++;
    }

    resArrSize = missingCount;
    return missingNums;
}