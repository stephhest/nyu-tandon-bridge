//
// sh7245_hw6_q2
//
// Question 2:
/* Implement a function bool isPalindrome (string str)
This function is given a string str containing a word,
and returns true if and only if str is a palindrome.
Then, write a program that reads a word from the user
and announces to the user if it is a palindrome of not. */
//
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);
/* Reads a string str and returns true if string is a 
palindrome, false if it is not. */

int main ()
{
    string str;
    bool result;

    cout<<endl<<"Please enter a word: ";
    cin>>str;

    result = isPalindrome(str);

    if (result == true)
        cout<<str<<" is a palindrome"<<endl;
    else
        cout<<str<<" is not a palindrome"<<endl;
    cout<<endl;

    return 0;

}

bool isPalindrome(string str)
{
    int str_length, last_index, index;
    bool result;

    str_length = str.length();
    last_index = str_length - 1;

    result = true;
    index = 0;
    while ((result == true) && (index <= last_index))
    {
        if (str[index] == (str[last_index-index]))
        {
            result = true;
            index++;
        }
        else
            result = false;
    }
    
    return result;
}