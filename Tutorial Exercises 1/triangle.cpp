/*
Write a program that can work out the area of a triangle from 3 sides. The formula is:

 area of triangle
Output should look like:

Input Validation: The sum of any two sides of a triangle is always greater than the third side.
The program should test whether a triangle can be constructed using the users input.
If a triangle cannot be constructed, the program should display an error message and exit.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

bool checkSides(float one, float two, float three) // a function that returns true/false
{
    bool thisIsOrNot = true; // make the variable with a true value
    if ((one + two <= three) or (one + three <= two) or (two + three <= one))
    {                               // if there is any pair that adds up to less that the third
        return thisIsOrNot = false; // it is not a triangle, so var is false
    }
    else // else - it is a triangle and var remains true
    {
        return thisIsOrNot;
    }
}

float triangleArea(float one, float two, float three) // a fuction to find the area of the triangle
{

    float s = (one + two + three) / 2;                          // get the perimeter of the triangle
    float calcArea = (s * (s - one) * (s - two) * (s - three)); // first set in getting the area
    calcArea = sqrt(calcArea);                                  // second step to get the area
    return calcArea;
}

void displayResults(float results, bool yesNo) // display the correct reply
{

    if (yesNo == false) // if it is not a triangle
    {
        cout << "This is not a valid triangle";
    }
    else // if it is a triangle
    {
        cout << "triangle is valid" << endl
             << "area is " << fixed << setprecision(2) << results; // display area to 2 decimal places
    }
}

int main() // execute all functions from here.
{
    float firstSide, secondSide, thirdSide, area; // make floats for input and to store returned values from each function
    bool triangleOrNot;                           // hold true or false return on whether it is a triangle or not.

    cin >> firstSide >> secondSide >> thirdSide; // input

    triangleOrNot = checkSides(firstSide, secondSide, thirdSide); // run function with a boolean return - store it here
    area = triangleArea(firstSide, secondSide, thirdSide);        // return a float and store it here
    displayResults(area, triangleOrNot);                          // run function
}