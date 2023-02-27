//
// sh7245_hw3_q2.cpp
//
/* Write a program that asks the user to input the current year and their
graduation year, and prints their graduation status. */
//
#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string name, status;
    int current_year, graduation_year, year_difference;
    
    cout<<endl<<"Please enter your name: ";
    cin>>name;
    cout<<"Please enter your graduation year: ";
    cin>>graduation_year;
    cout<<"Please enter current year: ";
    cin>>current_year;

    year_difference = graduation_year - current_year;

    if (year_difference >= 5)
        {
            status = "not in college yet";
            cout<<name<<", you are "<<status<<endl;
        }
        
    else if (year_difference <= 4 && year_difference >= 1)
        {
            if (year_difference == 4)
                status = "Freshman";
            else if (year_difference == 3)
                status = "Sophomore"; 
            else if (year_difference == 2)
                status = "Junior"; 
            else if (year_difference == 1)
                status = "Senior"; 
            cout<<name<<", you are a "<<status<<endl;
        }
  
    else if (year_difference <= 0)
        {
            status = "Graduated";
            cout<<name<<", you are "<<status<<endl<<endl;
        }


    return 0;

}