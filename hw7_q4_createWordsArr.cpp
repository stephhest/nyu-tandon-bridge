//
// sh7245_hw7_q4.cpp
//
// Question 4:
/* Implement a function that gets a string containing a sentence. 
When called, it should create and return a new array (of strings) that
 contains all the  words in the sentence. The function should also update
the output parameter with the logical size of the new array that was created. */
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
/* Takes a string (sentence) and output int parameter (outWordsArrSize). 
When called the function returns a new array (of strings) containing all 
the words in sentence, and updates outparameter size of new array. */

// MAIN TEST 
int main ()
{
    string sentence;
    cout<<"Please enter a sentence: ";
    getline (cin, sentence);

    int wordsArrSize;
    string *wordsArray = new string[0];

    wordsArray = createWordsArray (sentence, wordsArrSize);

    for (int i=0; i<wordsArrSize; i++)
        cout<<"wordsArray["<<i<<"]= "<<wordsArray[i]<<endl;
    cout<<"Size= "<<wordsArrSize<<endl;
    
    delete[]wordsArray;

    return 0;

}

// WORDS ARRAY FUNCTION 
string* createWordsArray(string sentence, int& outWordsArrSize)
{
    int line_length = sentence.length();

    string word;
    int wordCount = 0;

    for (int i=0; i<line_length; i++)
    {
        while ((sentence[i] != ' ') && (i<line_length))
        {
            word = word + sentence[i];
            i++;
        }
        wordCount++;
        word = "";
    }

    string *wordsArray = new string[wordCount];
    int word_index = 0;

    for (int i=0; i<line_length; i++)
    {
        while ((sentence[i] != ' ') && (i<line_length))
        {
            word = word + sentence[i];
            i++;
        }
        wordsArray[word_index] = word;
        word_index++;
        word = "";
    }
    
    outWordsArrSize = wordCount;
    return wordsArray;
    wordsArray = NULL;

}