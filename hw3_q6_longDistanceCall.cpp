//
// sh7245_hw3_q6.cpp
//
/* Write a program that computes the cost of a long-distance call.  The cost of the call
is determined by a schedule (see schedule in pdf). Inputs include day of the week, time 
call started, and length of call in minutes. Output will be the cost of the call. */
//
#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string day_of_week;
    int call_start_hour24, call_start_mins, call_length_mins;
    double minute_rate, cost_of_call;
    char temp;

    cout<<endl<<"Please enter the day of the week (Mo/Tu/We/Th/Fr/Sa/Su): ";
    cin>>day_of_week;
    cout<<"Please enter the call start time (in 24-hour format): ";
    cin>>call_start_hour24>>temp>>call_start_mins;
    cout<<"Please enter the length of the call (in minutes): ";
    cin>>call_length_mins;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if ((day_of_week == "Sa") || (day_of_week == "Su"))
    {
        minute_rate = 0.15;
        cost_of_call = call_length_mins * minute_rate;
        cout<<endl<<"The minute rate is: $"<<minute_rate<<endl;
        cout<<"The cost of this call is: $"<<cost_of_call<<endl<<endl;
    }
    else if ((day_of_week == "Mo") || (day_of_week == "Tu") || (day_of_week == "We")
    || (day_of_week == "Th") || (day_of_week == "Fr"))
    {
        if ((call_start_hour24 < 8) || (call_start_hour24 >= 18))
            minute_rate = 0.25;
        else 
            minute_rate = 0.40;

        cost_of_call = call_length_mins * minute_rate;
        cout<<endl<<"The minute rate is: $"<<minute_rate<<endl;
        cout<<"The cost of this call is: $"<<cost_of_call<<endl<<endl;
    }
    else
        cout<<endl<<"Error, please check formatting and try again."<<endl<<endl;
    

    return 0;


}