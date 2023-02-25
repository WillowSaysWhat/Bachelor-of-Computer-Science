/*
NY average is 85
Denver average is 88
Pheonix average is 106
If the averages temp rose by 15%
NY average would be <value>
Denver average would be <value>
Pheonix average would be <value>
*/

#include <iostream> //use in/out stream library.

using namespace std; // use standard namespace.

int main() // initialize integer function.
{
    int NY = 85;                                      // variable for NY temp.
    int Denver = 88;                                  // variable for Denver
    int Pheonix = 106;                                // variable for Pheonix
    float Variation = 1.15;                           // variable for the 15% variable.
    cout << "NY average is " << NY << endl;           // displays the temp in NY
    cout << "Denver average is " << Denver << endl;   // displays the temp in Denver
    cout << "Pheonix average is " << Pheonix << endl; // displays the temp in Pheonix
    cout << "If the averages temp rose by 15%" << endl;
    cout << "NY average would be " << NY * Variation << endl;         // displays the variation in NY(NY + 15%)
    cout << "Denver average would be " << Denver * Variation << endl; // displays the variation in Denver(Denver + 15%)
    cout << "Pheonix average would be " << Pheonix * Variation;       // displays the variation in Pheonix(Pheonix + 15%)

    return 0; // returns and integer.
}