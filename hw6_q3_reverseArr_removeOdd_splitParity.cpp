//
// sh7245_hw6_q3
//
// Question 3:
/* Implement three functions: void reverseArray, 
void removeOdd, void splitParity */
//
// TEST PROGRAM - See below for functions //
#include <iostream>
using namespace std;

void printArray(int arr[], int arr_size);

void reverseArray(int arr[], int arr_size);

void removeOdd(int arr[], int& arr_size);

void splitParity(int arr[], int arr_size);

int main ()
{
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    cout<<endl<<"** Function a: Reverse Array **"<<endl;
    cout<<"Original Array: ";
    printArray(arr1, arr1Size);
    cout<<"Reversed Array: ";
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    cout<<endl;

    cout<<"** Function b: Remove Odd **"<<endl;
    cout<<"Original Array: ";
    printArray(arr2, arr2Size);
    cout<<"Orginal Size: "<<arr2Size<<endl;
    cout<<"Updated Array: ";
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    cout<<"Updated Size: "<<arr2Size<<endl;
    cout<<endl;

    cout<<"** Function c: Split Parity **"<<endl;
    cout<<"Original Array: ";
    printArray(arr3, arr3Size);
    cout<<"Updated Array: ";
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    cout<<endl;

 return 0; 

}

// FUNCTIONS //

void printArray(int arr[], int arr_size)
{
    int index;

    for (index = 0; index < arr_size; index++)
        cout<<arr[index]<<" ";
    
    cout<<endl;
}

void reverseArray(int arr[], int arr_size)
{
    int index, mid_point, last_index, temp_first;
    mid_point = arr_size / 2;
    last_index = arr_size-1;

    for (index = 0; index < mid_point; index++)
    {
        temp_first = arr[index];
        arr[index] = arr[last_index-index];
        arr[last_index-index] = temp_first;
    }
}

void removeOdd(int arr[], int& arr_size)
{
    int index, last_index;

    index = 0;
    last_index = arr_size - 1;
    while (index < last_index)
    {
        if (arr[index] % 2 == 0)
            index++;
        else
        {
            for (int i = index; i <= last_index; i++)
            {
                arr[i] = arr[i+1];
            }
            arr_size--;
        } 
    }
}

void splitParity(int arr[], int arr_size)
{
    int index, temp_first, curr_last, last_index;
    last_index = arr_size - 1;

    index = 0;
    curr_last = last_index;
    while (index < curr_last)
    {
        if (arr[index] % 2 != 0)
            index++;
        else
        {
            if (arr[curr_last] % 2 != 0)
            {
                temp_first = arr[index];
                arr[index] = arr[curr_last];
                arr[curr_last] = temp_first;
                curr_last--;
            }
            else
                curr_last--;
        } 
    }
}