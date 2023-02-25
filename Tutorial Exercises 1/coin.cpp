/*
The outcome of tossing a fair coin can be either ‘Heads’ of ‘Tails’.
Write a program to simulate a coin toss.
The program should ask the user to enter either ‘H’ or ‘T’.
The program should then simulate tossing the coin by randomly generating either 1,
representing heads or 0 representing tails.
If the user's input should match the outcome of the toss,
the program should display “You Win”. Otherwise, it should display “You Lose”.

You Win
or
You Lose
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void TossTheCoin()     // function to take input (h or t) and generate random num.
{                      //
    char HeadsTails;   // char variable for input
    cin >> HeadsTails; // request input

    int randNum;       // variable to hold random num
    srand(time(NULL)); // part of the random num gen

    randNum = rand() % 2;                       // get the desired 0 to 1 by dividing rand() by n+1
                                                //
    if (HeadsTails == 'T' && randNum == 0)      // if input is tails and rand num is 0
    {                                           //
        cout << "You Win";                      // output win
    }                                           //
    else if (HeadsTails == 'H' && randNum == 1) // if input is heads and rand num is 1
    {
        cout << "You Win";  // output win
    }                       //
    else                    // otherwise
    {                       //
        cout << "You Lose"; // output lose
    }
}

int main()
{

    TossTheCoin(); // run function
}
