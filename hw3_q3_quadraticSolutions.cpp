//
// sh7245_hw3_q3.cpp
//
/* Write a program that asks the user to input 3 real numbers a, b and c,
which represent the parameters of the quadratic equation ax^2 + bx +c = 0.
The program should print the solution number_solutions as well as the solution. */
//
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

 int main () 
 {
    double sqrtResult; 
    double value_a, value_b, value_c;
    string number_solutions;
    double discriminant;
    double solution_1, solution_2;

    cout<<endl<<"Please enter value of a: ";
    cin>>value_a;
    cout<<"Please enter value of b: ";
    cin>>value_b;
    cout<<"Please enter value of c: ";
    cin>>value_c;

    discriminant = ((value_b * value_b) - (4.0 * value_a * value_c));
    solution_1 = (((-value_b) + sqrt(discriminant)) / (2.0 * value_a));
    solution_2 = (((-value_b) - sqrt(discriminant)) / (2.0 * value_a));

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    if ((value_a == 0) && (value_b == 0) && (value_c == 0))
    {
        number_solutions = "an infinite number of solutions";
        cout<<"This equation has "<<number_solutions<<endl;
    }
    else if ((value_a == 0) && (value_b == 0))
    {
        number_solutions = "no solution";
        cout<<"This equation has "<<number_solutions<<endl;
    }
    else if (discriminant < 0)
    {
        number_solutions = "no real solution";
        cout<<"This equation has "<<number_solutions<<endl;
    }
    else if (discriminant == 0)
    {
        number_solutions = "a single real solution";
        cout<<"This equation has "<<number_solutions;
        cout<<" x="<<solution_1<<endl;
    }
    else if (discriminant > 0)
    {
        number_solutions = "two real solutions";
        cout<<"This equation has "<<number_solutions;
        cout<<" x="<<solution_1;
        cout<<" x="<<solution_2<<endl;                
    }

    return 0;
}