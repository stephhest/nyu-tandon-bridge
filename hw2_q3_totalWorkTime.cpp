//
// sh7245_hw2_q3.cpp
//
// Question 3:
/* Suppose John and Bill worked for some time and we want to calculate the total time both 
of them worked. Write a program that reads number of days, hours, minutes each of them 
worked, and prints the total time both of them worked together as days, hours, minutes. */
//
#include <iostream>
using namespace std;

const int MINS_IN_DAY = 1440, MINS_IN_HOUR = 60;
int main ()
{
   int john_days, john_hours, john_minutes;
   int bill_days, bill_hours, bill_minutes;
   int both_total_minutes, both_days, both_hours, both_minutes;
   
    cout<<endl<<"Please enter the number of days John has worked: ";
    cin>>john_days;
    cout<<"Please enter the number of hours John has worked: ";
    cin>>john_hours;
    cout<<"Please enter the number of minutes John has worked: ";
    cin>>john_minutes;    

    cout<<endl<<"Please enter the number of days Bill has worked: ";
    cin>>bill_days;
    cout<<"Please enter the number of hours Bill has worked: ";
    cin>>bill_hours;
    cout<<"Please enter the number of minutes Bill has worked: ";
    cin>>bill_minutes;   

    both_total_minutes = ((john_days + bill_days) * MINS_IN_DAY) + ((john_hours + 
        bill_hours) * MINS_IN_HOUR) + (john_minutes + bill_minutes);
    both_days = both_total_minutes / MINS_IN_DAY;
    both_hours = (both_total_minutes - (both_days * MINS_IN_DAY)) / MINS_IN_HOUR;
    both_minutes = both_total_minutes - (both_days * MINS_IN_DAY) - (both_hours * 
        MINS_IN_HOUR);

    cout<<endl<<"The total time both of them worked together is: "<<both_days<<" days, "
        <<both_hours<<" hours and "<<both_minutes<<" minutes."<<endl<<endl;

    return 0;


}