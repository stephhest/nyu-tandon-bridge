//
// sh7245_hw6_q1
//
// Question 1:
/* Implement a function: int minInArray (int arr[], int arrSize)
This function  is given arr, an array of integers, and its logical
arr_size, arrSize. When called, it returns the min value in arr. 
Then, Write a program that reads from the user a sequence of 20 
integers into an array, and outputs the minimum value, and all the 
indices that value appears in the array */
//
#include <iostream>
using namespace std;

int minInArray (const int a[], int arr_size);
/* Reads an array of length arr_size and returns the value of the 
smallest element */

void PrintMinIndices (const int a[], int arr_size);
/* Reads an array of length arr_size, calculate the value of the
smallest element, and prints the index location(s) */

int main ()
{
    const int ARR_SIZE = 20;
    int arr_a[ARR_SIZE], index, curr_int, arr_a_min;
   
    cout<<endl<<"Please enter "<<ARR_SIZE<<" integers separated" 
    " by a space:"<<endl;
    
    // Read in ARR_SIZE integers and store in array A
    for (index = 0; index <= ARR_SIZE-1; index++)
    {
        cin>>curr_int;
        arr_a[index] = curr_int;
    }

    // Calculate min 
    arr_a_min = minInArray (arr_a, ARR_SIZE);

    // Print min, calculate and print index location(s) of min
    cout<<"The minimum value is "<< arr_a_min <<" and it is located"
    " in the following indices: ";
    PrintMinIndices(arr_a, ARR_SIZE); 
    cout<<endl<<endl;

    return 0;
}

int minInArray (const int a[], int arr_size)
{
    int index, curr_min;
    curr_min = a[0];
    for (index = 0; index <= arr_size-1; index++)
    {
        if (a[index] < curr_min)
            curr_min = a[index];
    }
    return curr_min;
}

void PrintMinIndices (const int a[], int arr_size)
{
    int index, final_min;
    
    final_min = minInArray(a, arr_size);

    for (index = 0; index <= arr_size-1; index++)
    {
        if (a[index] == final_min)
            cout<<index<<" ";
    }
}