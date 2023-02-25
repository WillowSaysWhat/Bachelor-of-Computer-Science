// a very simple program to show that I understand Linear Searching.
// Input a name and see if it appears in a list of names.
#include <iostream>

using namespace std;

int NumOfTimes(string &name, string list[], int &length) // finds the num of times the name appears in the list
{
    int numTimes = 0;                         // keeps count
    for (size_t i = 0; i < (length - 1); i++) // loops the length of the array
    {

        if (name == list[i]) // if the user input is equal to list index [i]
        {                    //
            numTimes++;      // add 1 to var
        }
    }

    return numTimes; // retrun variable to main
}
void displayOutcome(int &count, string &name) // displays output
{
    if (count > 0) // if name was in the list
    {
        cout << "The name " << name << " appears " << count << " times in the list";
    }
    else if (count == 0) // if name was not in the list
    {
        cout << "The name " << name << " does not appear in the list";
    }
}

int main()
{
    string listOfNames[] = {"Amy", "Rick", "John", "Patrick", "Marina", "Richard",
                            "Raj", "Marcia", "Amy", "Richard", "John", "Rick", "Patrick",
                            "Amy", "Raj", "John", "Patrick", "Richard"},  // array of names
        userName;                                                         // user input
    int listLength = sizeof(listOfNames) / sizeof(listOfNames[0]), times; // the length of the array

    cout << "Please enter name: "; // request for input
    cin >> userName;               // input to be store in userName

    times = NumOfTimes(userName, listOfNames, listLength); // get function to return value here
    displayOutcome(times, userName);                       // execute display funtion.
}