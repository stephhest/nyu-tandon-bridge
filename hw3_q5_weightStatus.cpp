//
// sh7245_hw3_q5.cpp
//
/* Write a program that prompts for weight and height of a person,
an dprints the weight status of that person. */
//
#include <iostream>
#include <string>
using namespace std;

const double KGS_IN_POUND = 0.453592;
const double METERS_IN_INCH = 0.0254;

int main ()
{
    int weight_pounds, height_inches;
    double weight_kgs, height_meters;
    double bmi_value;
    string weight_status;

    cout<<endl<<"Please enter weight (in pounds): ";
    cin>>weight_pounds;
    cout<<"Please enter height (in inches): ";
    cin>>height_inches;

    weight_kgs = weight_pounds * KGS_IN_POUND;
    height_meters = height_inches * METERS_IN_INCH;
    bmi_value = weight_kgs / (height_meters * height_meters);

    if (bmi_value < 18.5)
        weight_status = "Underweight";
    else if ((bmi_value >= 18.5) && (bmi_value < 25))
        weight_status = "Normal";
    else if ((bmi_value >= 25) && (bmi_value < 30))
        weight_status = "Overweight";
    else if (bmi_value >=30)
        weight_status = "Obese";

    cout<<"The weight status is: "<<weight_status<<endl<<endl;

    return 0;

}