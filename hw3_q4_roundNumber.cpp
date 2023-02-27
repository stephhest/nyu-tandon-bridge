//
// sh7245_hw3_q4.cpp
//
/* Write a program that asks a user to enter a real number, 
and then asks the user to enter the method by which they want to 
round that number.  Program should print the rounded result. */
//
#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main ()
{

    int rounding_selection, final_rounded_number;
    double user_real_number;

    cout<<endl<<"Please enter a Real number: "<<endl;
    cin>>user_real_number;
    cout<<"Choose your rounding method: "<<endl;
    cout<<"1. Floor round"<<endl;
    cout<<"2. Ceiling round"<<endl;
    cout<<"3. Round to the nearest whole number"<<endl;
    cin>>rounding_selection;

    if (user_real_number >= 0)
    {
        switch (rounding_selection)
        {
        case FLOOR_ROUND:
            final_rounded_number = int(user_real_number);
            cout<<final_rounded_number<<endl;
            break;
        case CEILING_ROUND:
            final_rounded_number = int(user_real_number + 1);
            cout<<final_rounded_number<<endl;
            break; 
        case ROUND:
            final_rounded_number = int(user_real_number + 0.5);
            cout<<final_rounded_number<<endl;
            break;
        default:
            cout<<"Error";
            break;
        }
    }
    else if (user_real_number < 0)
    {
        switch (rounding_selection)
        {
        case FLOOR_ROUND:
            final_rounded_number = int(user_real_number);
            cout<<final_rounded_number<<endl;
            break;
        case CEILING_ROUND:
            final_rounded_number = int(user_real_number - 1);
            cout<<final_rounded_number<<endl;
            break; 
        case ROUND:
            final_rounded_number = int(user_real_number - 0.5);
            cout<<final_rounded_number<<endl;
            break;
        default:
            cout<<"Error";
            break;
        }
    }


    return 0;

}