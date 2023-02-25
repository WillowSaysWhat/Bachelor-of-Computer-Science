// GETTING BAD OUTPUT FROM CODE GRADE

#include <iostream>

using namespace std;

int getInput(const int numStudents) // Value Returning Function
{
    int inputArr[numStudents], count = 0; // initialise array and int var for counting grades over 50

    for (int i = 0; i < numStudents; i++) // loop 10 times
    {
        cin >> inputArr[i]; // requests a single input per loop

        if (inputArr[i] > 50) // if the input is above 50
        {
            count++; // add 1 to the count
        }
    }
    return count; // returns amount to main
}

int main()
{
    const int numStudents = 10; // the number of grades that will be inputted
    int total;                  // var to hold function return value
    total = getInput(numStudents);
    cout << "The scores you entered include " << total << " percentages over 50."; // display
}