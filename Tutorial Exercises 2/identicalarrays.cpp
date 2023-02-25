// A very simple program that sorts and finds whether the numbers in 2 arrays are identical.

#include <iostream>
#include <algorithm>
using namespace std;

const int HowManyElements = 10;                // global constant variable with the number of inegers that can be added to an array
bool trueOrNot(int arrayOne[], int arrayTwo[]) // a function that find whether 2 arrays are identical
{
    bool TrueOrNot = true;                    // a var to hold boolean answer
    for (int i = 0; i < HowManyElements; i++) // loop 10 times and count up from 0 to 9 (10x)
    {                                         //
        if (arrayOne[i] != arrayTwo[i])       // check to see where an indexed number is NOT identical
        {                                     //
            TrueOrNot = false;                // if not identical, bool var becomes false
        }                                     //
    }                                         //
    return TrueOrNot;                         // return boolean result to main
}
void displayOutcome(bool outcome)                    // display the outcome
{                                                    //
    string display = "The arrays are not identical"; // default the string to the 'false/not' answer
    if (outcome)                                     // if boolean answer is true
    {                                                //
        display = "The arrays are identical";        // string variable become the 'true/is' answer
    }
    cout << display; // display the string
}

int main()
{

    int firstArray[HowManyElements], // ceate first and second array
        secondArray[HowManyElements];
    bool trueFalse; // boolean var

    cout << "Please input two groups of 10 numbers:" << endl; // user prompt

    for (int i = 0; i < HowManyElements; i++) // loop to the count of 10
    {
        cin >> firstArray[i]; // get user input for array 1
    }
    for (int i = 0; i < HowManyElements; i++) // loop to the count of 10
    {
        cin >> secondArray[i]; // get user input for array 2
    }
    sort(firstArray, firstArray + HowManyElements); // sort both arrays for most effective identification
    sort(secondArray, secondArray + HowManyElements);

    trueFalse = trueOrNot(firstArray, secondArray); // store comparison result here
    displayOutcome(trueFalse);                      // run display function with boolean argument
}