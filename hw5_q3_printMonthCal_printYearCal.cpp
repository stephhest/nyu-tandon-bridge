//
// sh7245_hw5_q3.cpp
//
// Question 3:
/* Write a program that interacts with a user to print a 
formatted yearly calendar for a specific year */
//
#include <iostream>
using namespace std;

int printMonthCalendar(int num_days, int starting_day);
/* Prints a formatted monthly calendar with the parameter num_days 
representing the number of days in a specific month, and starting_day
representing the day in the week for the first day of that month. 
Returns the day in the week of the last day of that month.*/

bool isLeapYear(int year);
/* Reads a year and returns TRUE if year is a leap year, 
returns FALSE otherwise */

void printMonthHeader(int month, int year);
/* Reads a month (in number format, 1-12) and a year, and prints 
the name of the month followed by the year. */

void printYearCalendar(int year, int starting_day);
/* Prints a formatted yearly calendar with the parameter "int year" 
representing a specific year, and "int starting_day" representing 
the day in the week for the first day of they year (1/1). */

int main ()
{
    int year, starting_day;

    cout<<endl<<"Enter a year: ";
    cin>>year;
    cout<<"Enter the day of the week for 1/1: ";
    cin>>starting_day;

    cout<<endl;
    printYearCalendar(year, starting_day);

    return 0;
}

int printMonthCalendar(int num_days, int starting_day)
{
    cout<<"Mon\tTue\tWed\tThr\tFri\tSat\tSun"<<endl;
    int blank_count, day_count, last_day, week0_days;
    for (blank_count = 1; blank_count <= starting_day-1;
    blank_count++)
        cout<<"\t";
    for (day_count = 1; day_count <= num_days; day_count++)
    {
        cout<<day_count<<"\t";
        if (((day_count + starting_day - 1) % 7 == 0) &&
        day_count != num_days)
            cout<<endl;
    }
    cout<<endl;
    week0_days = 8-starting_day;
    if ((num_days - week0_days) % 7 == 0)
        last_day = 7;
    else
        last_day = (num_days - week0_days) % 7;
    return last_day;
}

bool isLeapYear(int year)
{
    if(year % 400 == 0)
        return true;
    else if (year % 4 == 0)
    {
        if (year % 100 == 0)
            return false;
        else
            return true;
    }
    else
        return false;
}

void printYearCalendar(int year, int starting_day)
{
    int month_count, num_days, last_day, new_starting_day;
    for (month_count = 1; month_count <= 12; month_count++)
    {
        if (month_count == 2) 
        { 
            if (isLeapYear(year) == true)
                num_days = 29;
            else
                num_days = 28;
        }
        else if ((month_count == 4) || (month_count == 6) || 
        (month_count == 9) || (month_count == 11)) 
            num_days = 30;
        else 
            num_days = 31;
        printMonthHeader(month_count, year);
        last_day = printMonthCalendar(num_days, starting_day);
        if (last_day < 7)
            new_starting_day = last_day + 1;
        else
            new_starting_day = 1;
        starting_day = new_starting_day;
        cout<<endl;
    }
}

void printMonthHeader(int month, int year)
{
    if (month == 1)
        cout<<"January "<<year<<endl;
    else if (month == 2)
        cout<<"February "<<year<<endl;
    else if (month == 3)
        cout<<"March "<<year<<endl;
    else if (month == 4)
        cout<<"April "<<year<<endl;
    else if (month == 5)
        cout<<"May "<<year<<endl;
    else if (month == 6)
        cout<<"June "<<year<<endl;
    else if (month == 7)
        cout<<"July "<<year<<endl;
    else if (month == 8)
        cout<<"August "<<year<<endl;
    else if (month == 9)
        cout<<"September "<<year<<endl;
    else if (month == 10)
        cout<<"October "<<year<<endl;
    else if (month == 11)
        cout<<"November "<<year<<endl;
    else if (month == 12)
        cout<<"December "<<year<<endl;
}