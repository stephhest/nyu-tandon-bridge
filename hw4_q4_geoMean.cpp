//
// sh7245_hw4_q4.cpp
//
/* Write two versions of a program that reads a sequence of positive
integers from the user, calculates and prints the geometric mean. */
//
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    // Section A
    int entries;
    int count_a, curr_integer_a, product_integers_a;
    double geo_mean_a;

    cout<<endl<<"Section A"<<endl;
    cout<<"Please enter the length of a sequence: ";
    cin>>entries;
    cout<<"Please enter your sequence:"<<endl;

    product_integers_a = 1;
    for (count_a = 1; count_a <= entries; count_a++)
    {
        cin>>curr_integer_a;
        product_integers_a *= curr_integer_a;
    }
        
    geo_mean_a = pow(double(product_integers_a), (1.0/double(entries)));
    cout<<"The geometric mean is "<<geo_mean_a<<endl;

    // Section B
    int end_of_input = false;
    int count_b, curr_integer_b, product_integers_b; 
    double geo_mean_b;

    cout<<endl<<"Section B"<<endl;
    cout<<"Please enter a non-empty sequence of positive integers, each"
    " one in a separate line. End your sequence by typing -1:"<<endl;

    product_integers_b = 1;
    count_b = 0;
    while (end_of_input == false)
    {
        cin>>curr_integer_b;
        if (curr_integer_b == -1)
            end_of_input = true;
        else
        {
            product_integers_b *= curr_integer_b;
            count_b++;
        }
    }

    geo_mean_b = pow(double(product_integers_b), (1.0/double(count_b)));
    cout<<"The geometric mean is "<<geo_mean_b<<endl;
    
    return 0;
}