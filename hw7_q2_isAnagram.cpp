//
// sh7245_hw7_q2.cpp
//
// Question 2:
/* Write a program that determines if two lines are anagrams. */
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void getLetters (string line, vector<char>& vect);
/* Takes a single line as input, as well as an empty vector,
and fills the vector with the line's letters in alpha order. */

int main ()
{
    string line1, line2;

    cout<<endl;
    cout<<"Please enter line 1 of text: "<<endl;
    getline (cin, line1);
    cout<<endl;

    cout<<"Please enter line 2 of text: "<<endl;
    getline (cin, line2);
    cout<<endl;

    vector<char> v1;
    vector<char> v2;

    getLetters(line1, v1);
    getLetters(line2, v2);

    if (v1 == v2)
        cout<<"These lines are anagrams."<<endl;
    else 
        cout<<"These lines a NOT anagrams."<<endl;
    cout<<endl;
    
    return 0;
}

void getLetters (string line, vector<char>& vect)
{
    int line_length = line.length();

    vector <char> v_temp;
    char target_uc = 'A', target_lc = 'a';
    for (int alphai=0; alphai<=26; alphai++)
    {
        for (int i=0; i<line_length; i++)
        {
            if ((line[i] == target_uc) || (line[i] == target_lc))
            {
                v_temp.push_back(target_lc);
            }
        }
        target_uc++;
        target_lc++;
    }
    
    vect = v_temp;

}