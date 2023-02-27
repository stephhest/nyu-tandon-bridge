//
// sh7245_hw6_q4
//
// Question 4:
/* Write a program to simulate the authentication process. 
Store an actual 5-digit PIN number in your program as a constant. 
The program should use an array to assign random numbers to 
the digits from 0 to 9. Output the random digits to the screen, 
input the response from the user, and output whether or not the 
user’s response correctly matches the PIN number. */
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void printArrPIN(int arr[], int arr_size);
/* Generates and prints an array (arr) of size (arr_size)
containing digit options for PIN incrementing from 0. */

void printArrRand(int arr[], int arr_size);
/* Generates and prints an array (arr) of size (arr_size)
containing a randomized collection of 1s, 2s, and/or 3's. */

int convertPINtoRand(int user_PIN, int arrPIN[], int arrRand[]);
/* Converts a correct user PIN to a randomized number based the 
indices of arrPIN and arrRand, returns converted user_PIN. */

int main ()
{
    const int PIN_10_DIGITS=10;
    const int user_PIN=12345;
    int arr_PIN[PIN_10_DIGITS], arr_Rand[PIN_10_DIGITS];
    int user_entry, converted_PIN;

    // Generate and print PIN and Rand arrays
    cout<<endl;
    cout<<"Please enter your PIN according to the following mapping:"<<endl;
    printArrPIN(arr_PIN, PIN_10_DIGITS);
    printArrRand(arr_Rand, PIN_10_DIGITS);
    cin>>user_entry;
    
    // Convert PIN to number based on Rand array digits
    converted_PIN = convertPINtoRand(user_PIN, arr_PIN, arr_Rand);
    
    // Compare converted PIN and entry, annouce if entry is correct
    if (converted_PIN == user_entry)
        cout<<"Your PIN is correct"<<endl;
    else
        cout<<"Your PIN is not correct"<<endl;
    
    cout<<endl;

    return 0;
}

void printArrPIN(int arr[], int arr_size)
{
    int index;
    cout<<"PIN:\t";
    for (index = 0; index < arr_size; index++)
    {
        arr[index] = index;
        cout<<arr[index]<<" ";
    }
    cout<<endl;

}

void printArrRand(int arr[], int arr_size)
{
    int index, curr_rand_num;
    srand(time(0));
    cout<<"NUM:\t";
    for (index = 0; index < arr_size; index++)
    {
        curr_rand_num = ((rand() % 3) + 1);
        arr[index] = curr_rand_num;
        cout<<arr[index]<<" ";
    }
    cout<<endl;
}

int convertPINtoRand(int user_PIN, int arrPIN[], int arrRand[])
{
    int curr_num, digits_place, target_digit, converted_PIN;
    curr_num = user_PIN;
    converted_PIN = 0;
    for (digits_place=4; digits_place >=0; digits_place--)
    {
        target_digit = curr_num / pow(10,digits_place);
        int index = 0;
        bool digit_match = false;
        while (digit_match == false)
        {
            if (target_digit == arrPIN[index])
            {
                converted_PIN += (arrRand[index]*pow(10,digits_place));
                digit_match = true;
                curr_num -= (target_digit * pow(10,digits_place)); 
            }
            else
                index++;
        }
    }
    return converted_PIN;
}
