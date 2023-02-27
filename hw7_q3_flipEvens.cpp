//
// sh7245_hw7_q3.cpp
//
// Question 3:
/* Implement a function that gets an array of integers arr and its logical 
size arrSize. When called, it should reorder the elements of arr so that:
    1. All the odd numbers come before all the even numbers
    2. The odd numbers will keep their original relative order
    3. The even numbers will be placed in a reversed order (relative to  
    their original order). */
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void oddsKeepEvensFlip (int arr[], int ARR_SIZE);
/* Takes an array (arr) of size (ARR_SIZE), shifts all odd numbers
prior to evens in their original relative order, and reverses the
order of the even numbers (relative to their original order).
*/

// MAIN TEST
int main ()
{
    const int ARR_SIZE = 6;
    int arr[ARR_SIZE] = {5, 2, 11, 7, 6, 4};

    cout<<endl;
    cout<<"Original array: ";
    for (int i=0; i<ARR_SIZE; i++)
        cout<<arr[i]<<" ";
    cout<<endl<<endl;

    oddsKeepEvensFlip(arr, ARR_SIZE);

    cout<<"New array: ";
    for (int i=0; i<ARR_SIZE; i++)
        cout<<arr[i]<<" ";
    cout<<endl<<endl;

    return 0;
}

// ODDS KEEP EVENS FLIP FUNCTION
void oddsKeepEvensFlip (int arr[], int ARR_SIZE)
{
    vector<int> v_odds;
    vector<int> v_evens;

    for (int i=0; i<ARR_SIZE; i++)
    {
        if (arr[i] % 2 != 0)
            v_odds.push_back(arr[i]);
        else
            v_evens.push_back(arr[i]);
    }

   for (int i=0; i<v_odds.size(); i++)
       arr[i] = v_odds[i];

   int evens_start = v_odds.size();
   int last_even = v_evens.size() - 1;

   for (int i=evens_start; i<ARR_SIZE; i++)
   {
       arr[i] = v_evens[last_even];
       last_even--;
   }

}