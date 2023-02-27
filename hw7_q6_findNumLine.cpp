//
// sh7245_hw7_q6.cpp
//
// Question 6:
/* Write two versions of a program that reads from the user a sequence of
positive integers ending with -1, and another positive integer that the 
user wishes to search for. The programs should print all the line numbers
in sequence that contain num, or message saying it does not show at all. */
//
#include <iostream>
#include <vector>
using namespace std;

int main1 (); // First version of program

int main2 (); // Second version of program

void searchArray(int arr[], int arr_size, int num);
/* Takes an array (arr) of size (arr_size) containing a sequence of 
integers, and a target number (num). Function searches the array for that 
number and prints which lines (if any) the target number is shown. */

void searchVector(vector<int> v, int vSize, int num);
/* Takes a vector (v) of size (vSize) containing a sequence of integers,
and a target number (num). Function searches the vector for that 
number prints which lines (if any) the target number is shown. */

// MAIN - TEST
int main ()
{
    main1();

    main2();

    return 0;
}

// MAIN 1 FUNCTION
int main1 ()
{
    cout<<endl;
    cout<<"Please enter a sequence of positive integers, "
    "each in a separate line. "<<endl;
    cout<<"End your input by typing -1. "<<endl;

    int arrSize = 0;
    int* newArr = new int[arrSize];
    int next;
    
    bool isPos = true;
    int i = 0;
    while (isPos == true)
    {
        cin>>next;
        if (next < 0)
            isPos = false;
        else
        {
            newArr[i] = next;
            i++;
            arrSize++;
        }
    }

    int num;

    cout<<"Please enter the number you want to search:"<<endl;
    cin>>num;

    searchArray (newArr, arrSize, num);
    cout<<endl;

    delete[]newArr;

    return 0;
}

// MAIN 2 FUNCTION
int main2 ()
{
    cout<<endl;
    cout<<"Please enter a sequence of positive integers, "
    "each in a separate line. "<<endl;
    cout<<"End your input by typing -1. "<<endl;

    vector<int> inputVect;
    int next;
    bool isPos = true;
    while (isPos == true)
    {
        cin>>next;
        if (next < 0)
            isPos = false;
        else
            inputVect.push_back(next);
    }
    
    int vectSize = inputVect.size();
    int num;

    cout<<"Please enter the number you want to search:"<<endl;
    cin>>num;    

    searchVector(inputVect, vectSize, num);
    cout<<endl;

    return 0;
}

// ARRAY SEARCH FUNCTION - SEARCH ARRAY AND PRINT TARGET LINES
void searchArray(int arr[], int arr_size, int num)
{
    int num_count = 0;
    int i=0;

    for (i=0; i<arr_size; i++)
    {
        if (arr[i] == num)
            num_count++;
    }
 
    if (num_count == 0)
        cout<<num<<" does not show in any lines. ";

    else if (num_count > 0)
    {
        int* linesArr = new int[num_count];
        int arrIndex = 0;
        for (i=0; i<arr_size; i++)
        {
            if (arr[i] == num)
            {
                linesArr[arrIndex] = i+1;
                arrIndex++;
            }
        }

        int lastIndex = num_count - 1;

        if (lastIndex == 0)
            cout<<num<<" shows in line "<<linesArr[0]<<".";
        else
        {
            cout<<num<<" shows in lines ";
            for (i=0; i<num_count; i++)
            {
                if (i < lastIndex)
                    cout<<linesArr[i]<<", ";
                else if (i == lastIndex)
                    cout<<linesArr[i]<<".";
            }
        }
        cout<<endl;

        delete[]linesArr;
    }
    
}

// VECTOR SEARCH FUNCTION - SEARCH VECTOR AND PRINT TARGET LINES
void searchVector(vector<int> v, int vSize, int num)
{
    int num_count = 0;
    vector<int> linesVect;

    for (unsigned int i=0; i<vSize; i++)
    {
        if (v[i] == num)
        {
            linesVect.push_back(i+1);
            num_count++;
        }    
    }
 
    if (num_count == 0)
        cout<<num<<" does not show in any lines. ";

    else if (num_count > 0)
    {
        int lastIndex = num_count - 1;

        if (lastIndex == 0)
            cout<<num<<" shows in line "<<linesVect[0]<<".";
        else
        {
            cout<<num<<" shows in lines ";
            for (unsigned int i=0; i<num_count; i++)
            {
                if (i < lastIndex)
                    cout<<linesVect[i]<<", ";
                else if (i == lastIndex)
                    cout<<linesVect[i]<<".";
            }
        }
        cout<<endl;
    }
}