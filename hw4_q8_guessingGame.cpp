//
// sh7245_hw4_q8.cpp
//
/* Implement a number guessing game. The program should randomly choose an 
integer between 1 and 100 (inclusive), and have the user try to guess that number. */
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main ()
{
    srand(time(0));
    const int RAND_NUM = (rand()%100)+1;
    int current_user_guess;
    int guess_rem;
    int guess_count = 0; 
    int range_min = 1;
    int range_max = 100;

    cout<<endl<<"I thought of a number between "<<range_min<<" and "
    <<range_max<<"! Try to guess it."<<endl;

    for (guess_rem = 5; guess_rem > 0; guess_rem--)
    {
        cout<<"Range: ["<<range_min<<", "<<range_max<<"], ";
        cout<<"Number of guesses left: "<<guess_rem<<endl;
        cout<<"Your guess: ";
        cin>>current_user_guess;
        guess_count++;
        if ((guess_rem == 1) && (current_user_guess != RAND_NUM))
            cout<<"Out of guesses! My number is "<<RAND_NUM<<endl<<endl;
    
        else if (current_user_guess == RAND_NUM)
        {
            cout<<"Congrats! You guessed my number in ";
            cout<<guess_count<<" guesses."<<endl<<endl;
            guess_rem = 0;
        }
        else
        {
            if (current_user_guess < RAND_NUM)
            {
                cout<<"Wrong! My number is bigger."<<endl<<endl;
                range_min = (current_user_guess + 1);
            }
            else
            {
                cout<<"Wrong! My number is smaller."<<endl<<endl;
                range_max = (current_user_guess - 1);                
            }
        }
    }
    
    return 0;
}