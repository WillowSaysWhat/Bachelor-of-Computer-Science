
#include <iostream>
#include <iomanip>

using namespace std;

class Time24 // create class

{
private:
    int hours, // variables for the class
        minutes,
        seconds;

public:
    Time24() // default constructor that sets attributes to zero
    {
        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
    }

    void CheckParameters(int TheHour, int TheMins, int TheSecs) // checks whether hours (0-23),
    {                                                           // mins, and secs(0-59) are corrct
        if ((TheHour >= 0 && TheHour <= 23) && (TheMins >= 0 && TheMins <= 59) && (TheSecs >= 0 && TheSecs <= 59))
        {                          // if hours(0-23), mins(0-59), and secs(0-59) are correct
            this->hours = TheHour; // set all attributes to user input
            this->minutes = TheMins;
            this->seconds = TheSecs;
        } // else, leave them as zero (0,0,0)
    }

    void Display12hr() // creates 12 hours via a loop and displays outcome
    {
        string AmPm = "AM";     // string for "AM"/"PM"
        int TwelveHour = hours; // var to hold 12-hour time

        if (hours > 12) // if the variable value is higher than 12
        {
            TwelveHour -= 12; // minus 12 to get 12-hour time
        }

        if (hours > 11) // if hours is above 11
        {
            AmPm = "PM"; // make the string "PM"
        }

        cout << "12-hour format: " << setw(2) << setfill('0') << TwelveHour << ":"
             << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " "
             << AmPm << endl; // print out 12-hour time with extra zeroes where needed with set fill
    }
    void Display24hr() // displays 24-hour time
    {                  // 24-hour format: <value>
        cout << "24-hour format: " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes
             << ":" << setw(2) << setfill('0') << seconds << endl; // print out 12-hour time with extra zeroes where needed with set fill
    }
    void DisplayGreeting() // decides and displays greeting
    {
        if (hours >= 6 && hours <= 11)                        // if the hours are between 6 and 11...
        {                                                     //
            cout << "Good Morning";                           // display this
        }                                                     //
        else if (hours >= 12 && hours <= 17)                  // if the hour is between 12 and 17...
        {                                                     //
            cout << "Good Afternoon";                         // display this
        }                                                     //
        else if (hours >= 18 && hours <= 22)                  // if the hour is between 18 and 22..
        {                                                     //
            cout << "Good Evening";                           // display this
        }                                                     //
        else if ((hours == 23) || (hours >= 0 && hours <= 5)) // if the time is between 23 and 5...
        {                                                     //
            cout << "Time to sleep";                          // display this
        }
    }
};

int main()
{
    int userHour, // create 3 variables for user input
        userMin,
        userSec;

    cin >> userHour >> userMin >> userSec; // requests user input 3 times
    Time24 WhatTimeIsIt;                   // creates object
    WhatTimeIsIt.CheckParameters(userHour, userMin, userSec);
    WhatTimeIsIt.Display12hr();
    WhatTimeIsIt.Display24hr();
    WhatTimeIsIt.DisplayGreeting();
}
