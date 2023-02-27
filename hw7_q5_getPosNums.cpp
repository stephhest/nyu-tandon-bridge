//
// sh7245_hw7_q5.cpp
//
// Question 5:
/* Write four versions of a function getPosNums that gets an array of 
integers arr, and its logical size. When called it creates a new array 
containing only the positive numbers from arr.*/
//
#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
/* Takes as input an array in integers (arr) of size (arrSize), and
returns the base address of a new array containing the positive numbers.
Updates output parameter outPosArrSize with new array’s logical size. */

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
/* Takes as input an array in integers (arr) of size (arrSize), and
returns the base address of a new array containing the positive numbers.
Updates pointer parameter outPosArrSize with new array’s logical size. */

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
/* Takes as input an array in integers (arr) of size (arrSize), then
updates the output parameter outPosArr with the base addres of a new array 
containing the positive numbers, and updates output paramter outPosArrSize
with the new array's logical size. */

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
/* Takes as input an array in integers (arr) of size (arrSize), then
updates the pointer parameter outPosArrPtr with the base addres of a new array 
containing the positive numbers, and updates pointer parameter outPosArrSizePtr
with the new array's logical size. */

int main ()
{
    const int ARR_SIZE = 6;
    int myArr[ARR_SIZE] = {3, -1, -3, 0, 6, 4};

    int Arr1Size=0, Arr2Size=0, Arr3Size=0, Arr4Size=0;
    int* Arr2SizePtr = &Arr2Size;
    int* Arr4SizePtr = &Arr4Size;
    int i;

    int* newArr1 = new int[Arr1Size]; // set equal to function1
    int* newArr2 = new int[Arr2Size]; // set equal to function2
    int* newArr3 = new int[Arr3Size]; // use as parameter in function3
    int* newArr4 = new int[Arr4Size]; 
    int* newArr4Ptr = &newArr4[0];

    newArr1 = getPosNums1 (myArr, ARR_SIZE, Arr1Size);
    cout<<endl<<"FUNCTION 1:"<<endl;
    for (i=0; i<Arr1Size; i++)
        cout<<"newArr1["<<i<<"]= "<<newArr1[i]<<endl;
    cout<<"newArr1 SIZE = "<<Arr1Size<<endl;

    newArr2 = getPosNums2(myArr, ARR_SIZE, Arr2SizePtr);
    cout<<endl<<"FUNCTION 2:"<<endl;
    for (i=0; i<Arr2Size; i++)
        cout<<"newArr2["<<i<<"]= "<<newArr2[i]<<endl;
    cout<<"newArr2 SIZE = "<<Arr2Size<<endl;

    getPosNums3(myArr, ARR_SIZE, newArr3, Arr3Size);
    cout<<endl<<"FUNCTION 3:"<<endl;
    for (i=0; i<Arr3Size; i++)
        cout<<"newArr3["<<i<<"]= "<<newArr3[i]<<endl;
    cout<<"newArr3 SIZE = "<<Arr3Size<<endl;

    getPosNums4(myArr, ARR_SIZE, &newArr4, Arr4SizePtr);
    cout<<endl<<"FUNCTION 4:"<<endl;
    for (i=0; i<Arr4Size; i++)
        cout<<"newArr4["<<i<<"]= "<<newArr4[i]<<endl;
    cout<<"newArr4 SIZE = "<<Arr4Size<<endl;    

    cout<<endl; 

    delete[]newArr1; 
    delete[]newArr2; 
    delete[]newArr3;
    delete[]newArr4;

    return 0;
}

// FUNCTION 1
int* getPosNums1(int* arr, int arrSize, int& outPosArrSizePtr)
{
    int posNumCount = 0;
    int i;
    for (i=0; i<arrSize; i++)
    {
        if (arr[i]>0)
            posNumCount++;
    }

    int* newArr1 = new int[posNumCount];
    int newArr1i = 0;

    for (i=0; i<arrSize; i++)
    {
        if (arr[i]>0)
        {
            newArr1[newArr1i] = arr[i];
            newArr1i++;
        }
    }

    outPosArrSizePtr = posNumCount;
    return newArr1;
}

// FUNCTION 2
int* getPosNums2(int* arr, int arrSize, int* outPosArrSize)
{
    int posNumCount = 0;
    int i;
    for (i=0; i<arrSize; i++)
    {
        if (arr[i]>0)
            posNumCount++;
    }

    int* newArr2 = new int[posNumCount];
    int newArr2i = 0;

    for (i=0; i<arrSize; i++)
    {
        if (arr[i]>0)
        {
            newArr2[newArr2i] = arr[i];
            newArr2i++;
        }
    }

    *outPosArrSize = posNumCount;
    return newArr2;
}

// FUNCTION 3
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
{
    int posNumCount = 0;
    int i;
    for (i=0; i<arrSize; i++)
    {
        if (arr[i]>0)
            posNumCount++;
    }

    int* newArr3 = new int[posNumCount];
    int newArr3i = 0;

    for (i=0; i<arrSize; i++)
    {
        if (arr[i]>0)
        {
            newArr3[newArr3i] = arr[i];
            newArr3i++;
        }
    }

    outPosArr = newArr3;
    outPosArrSize = posNumCount;

}

// FUNCTION 4
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
{
    int posNumCount = 0;
    int i;
    for (i=0; i<arrSize; i++)
    {
        if (arr[i]>0)
            posNumCount++;
    }

    int* newArr4 = new int[posNumCount];
    int newArr4i = 0;

    for (i=0; i<arrSize; i++)
    {
        if (arr[i]>0)
        {
            newArr4[newArr4i] = arr[i];
            newArr4i++;
        }
    }

    *outPosArrPtr = &newArr4[0];
    *outPosArrSizePtr = posNumCount;

}