// The population of the world is 7.7 billion (7700000000). Write a program that displays what the population
//  is if increases by 10%, 15%, and 20%.
//  output.
// The world population is 7700000000
// if the world population rose by 10% it would be <value>
// if the world population rose by 15% it would be <value>
// if the world population rose by 20% it would be <value>

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
     long long OriginalPopulation = 7700000000; // make a variable that can hold a very long number
     int Percent = 10;                          // varible to hold the percent.

     cout << "The world population is " << OriginalPopulation << endl             // display the original population from the long var
          << "if the world population rose by " << Percent << "% it would be "    // diplays string
          << (OriginalPopulation + (Percent * OriginalPopulation / 100)) << endl; // displays the pop if risen by 10%
     Percent += 5;                                                                // adds 5 to this veriable
     cout << "if the world population rose by " << (Percent) << "% it would be "  // displays string
          << ((Percent * OriginalPopulation / 100) + OriginalPopulation) << endl; // displys the pop if risen by 15%
     Percent += 5;                                                                // adds 5 to this variable
     cout << "if the world population rose by " << (Percent) << "% it would be "  // displays string
          << ((Percent * OriginalPopulation / 100) + OriginalPopulation);         // displays the pop if risen by 20%
}