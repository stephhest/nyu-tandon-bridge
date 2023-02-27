//
// sh7245_hw6_q6
//
// Question 6:
/* Write a program that reads in a line of text and outputs the 
line with all the digits in all integer numbers replaced with 'x'. */
//
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string line, temp_substr;

    cout<<endl;
    cout<<"Please enter a line of text: "<<endl;
    getline(cin,line);

    int line_index, line_length;
    int substr_index, substr_start, substr_length, substr_end;
    int digit_counter, alpha_counter; 

    line_length = line.length();

    for(line_index = 0; line_index < line_length; line_index++)
    {
        // For each substring / block of text before a space:
        if (line[line_index] != ' ')
        {
            temp_substr.clear();
            substr_start = line_index;
            digit_counter = 0;
            alpha_counter = 0;
            while (line[line_index] != ' ' && line_index < line_length)
            {
                temp_substr += line[line_index];
                if (line[line_index] >= '0' && line[line_index] <= '9')
                    digit_counter ++;
                else
                    alpha_counter++;
                line_index++;
            }
            // If substring is DIGITS ONLY:
            if ((alpha_counter == 0) && (digit_counter > 0))
            {
                substr_length = temp_substr.length();
                substr_end = substr_start + substr_length;
                for (substr_index = substr_start; substr_index < substr_end;
                 substr_index++)
                {
                    line[substr_index] = 'x';
                }
            }
        }
    }

    // New Line:
    cout<<line<<endl;
    cout<<endl;

    return 0;

}