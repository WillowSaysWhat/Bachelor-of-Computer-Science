/*
A car travels from City X to City Z, through City Y. Its average speed can be calculated by:

  Equation


 Write a function named averageVelocity that accepts the distance between X and Y,
 and Y and Z in kilometres, and the time take to from X to Y, and from Y to Z in hours,
 as arguments, and returns the average velocity I kilometres per hour.
 Write a program that asks the user to input each argument, and then calls the function and
 displays the average velocity.

Output Should look like:
Average speed was <value>Km/H
*/

#include <iostream>

using namespace std;

float averageVelocity(float fromXY, float fromYZ, float hoursXY, float hoursYZ) // required function with 4 float arguments
{                                                                               //
  return (fromXY + fromYZ) / (hoursXY + hoursYZ);                               // returning equation
}

int main()
{
  float fromXtoY, fromYtoZ, hoursXtoY, hoursYtoZ, velocity; // creating a float for each argument and one to return the average velocity
  cin >> fromXtoY >> fromYtoZ >> hoursXtoY >> hoursYtoZ;    // requesting input into 4 of the variables

  velocity = averageVelocity(fromXtoY, fromYtoZ, hoursXtoY, hoursYtoZ); // calling function to return to this variable.
  cout << "Average speed was " << velocity << "Km/H";                   // displaying results.
}
