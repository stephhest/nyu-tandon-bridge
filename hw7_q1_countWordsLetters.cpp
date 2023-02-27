//
// sh7245_hw7_q1.cpp
//
// Question 1:
/*Write a program that will read in a line of text and output the number 
of words in the line and the number of occurrences of each letter. */
//
#include <iostream>
#include <string>
using namespace std;

void printWordCount (string line);
// Takes a single line as input and prints the number of words.

void printLetterCount(string line);
/* Takes a single line as input and print the number of each
letter of the alphabet it contains. */

int main ()
{
    string line;
    cout<<"Please enter a line of text: "<<endl;
    getline (cin, line);

    printWordCount(line);
    printLetterCount(line);

    return 0;
}

void printWordCount (string line)
{
    int line_length = line.length();
    int word_count = 0;
    for (int i=0; i<line_length; i++)
    {
        if ((line[i] == ' ') || (line[i] == '.') || (line[i] == ',') 
        || (i+1 == line_length))
            word_count++;
    }
    cout<<word_count<<"\twords"<<endl;
}

void printLetterCount(string line)
{
    int line_length = line.length();
    int target_count = 0;

    char target_uc = 'A', target_lc = 'a';

    for (int alphai=0; alphai<=26; alphai++)
    {
        target_count = 0;
        for (int i=0; i<line_length; i++)
        {
            if ((line[i] == target_uc) || (line[i] == target_lc))
                target_count++;
        }
        if (target_count > 0)
            cout<<target_count<<"\t"<<target_lc<<endl;
        target_uc++;
        target_lc++;
    }
}