/*
Bob spent 4 hours and 30 minutes per day working on a project and jenny spent 3 hours and 15 minutes per day
on the same project. Write a program that asks the user to input the number of days bob and jenny worked
on the project and calculates and displays the total time spent by each in hours and minutes.

Bob worked a total of < value > hours and < value > minutes  on the project
Jenny worked a total of < value > hours and < value > minutes on the project
*/
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float bobHour = 4, bobMin = 30; // make floats to hold bob's hours-in-a-day && bob's minutes-in-a-day

    float jennyHour = 3, jennyMin = 15; // make floats to hold Jenny's hours-in-a-day && minutes-in-a-day

    float minutes, Newhours, NewMinutes; // make floats to hold calculations to separate decimal from whole

    float bobDays, jennyDays;
    cin >> bobDays >> jennyDays; // input the anount of days they have worked in a week.

    minutes = (bobMin * bobDays) / 60; // Bob's minutes times(*) how many days he worked

    Newhours = floor(minutes); // collecting the whole numbers only, from the calculation above

    NewMinutes = (minutes - Newhours) * 60; // using Newhours to remove the whole number so only the decial remains. Then making it a whole number
    Newhours += (bobDays * bobHour);        // timesing(*) the answer from line(28) and adding it to Newhours.

    cout << "Bob worked a total of " << Newhours << " hours and " << NewMinutes << " minutes on the project" << endl;

    minutes = (jennyMin * jennyDays) / 60; // we do the same for Jenny

    Newhours = floor(minutes);

    NewMinutes = (minutes - Newhours) * 60;
    Newhours += (jennyDays * jennyHour);

    cout << "Jenny worked a total of " << Newhours << " hours and " << NewMinutes << " minutes on the project";
}