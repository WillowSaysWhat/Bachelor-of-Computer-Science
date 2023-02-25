/*
Output should look like:

What is the speed of the vehicle in mph? 40
How many hours has it travelled? 3
Hour       Miles Travelled
--------------------------
1          40
2          80
3          120*/

#include <iostream>
#include <iomanip>

using namespace std;

void distance(short howFast, short time) // function to print out the distance
{

    cout << "Hour " // displaying the headings
         << " Miles Travelled" << endl;
    cout << "---------------------" << endl;

    int distance = 1;                                             // var to total iteration * speed
                                                                  //
    for (int h = 1; h < time + 1; h++)                            // loop so we can iterate from 1 to time(hours travelled)
    {                                                             //
        distance = h * howFast;                                   // we times the speed by each iteration.
        cout << left << setw(6) << h << left << distance << endl; // display each iteration
    }
}

int main()
{
    int speed, hours;       // make a var for speed and hours travelled
                            //
    cin >> speed >> hours;  // request input
                            //
    distance(speed, hours); // send to function
}