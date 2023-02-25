/*
Write a program that determines which of a company’s four divisions
(Northeast, Southeast, Northwest and southwest) had the greatest sales for a quarter.
It should include the following two functions, which are called by main.

Double getSales() is passed the name of a division. It asks the user for a division’s quarterly sales figure,
validates the input is not less than 0, then returns it. It should be called once for each division.

Void findHighest() is passed the four sales totals.

It determines which is the largest and prints the name of the high grossing division, along with its sales figure.

Output should look like:

The <value> division had the highest sales this quarter.
"Their sales were $<value>"
*/
#include <iostream>
#include <iomanip>

using namespace std;

double getSales() // required function
{
    double quarterSales = 0; // make a variable that holds the quarterly sales

    do
    {
        cin >> quarterSales;    // request input
    } while (quarterSales < 0); // if the value of quarterSales is above zero, break this loop
    return quarterSales;        // return the variable
}

void findHeighest(double NorEast, double SoEast, double NorWest, double SoWest) // required function
{
    double Largest = NorEast; // make a variable and place NorthEast value into it
    string areaNames[4]{
        "Northeast",
        "Southeast",
        "Northwest",
        "Southwest", // an array with all the division names
    },
        largestName = areaNames[0]; // make a variable with NorthEast string in it

    if (Largest < SoEast) // if Largest's current value is smaller than NorWest
    {
        Largest = SoEast;           // Largest is not NorWest
        largestName = areaNames[1]; // largestName is now "Northwest"
    }
    if (Largest < NorWest) // if Largest is less than SoWest
    {
        Largest = NorWest;          // SoWest is now the Largest value
        largestName = areaNames[2]; // largestName is now "Southwest"
    }
    if (Largest < SoWest) // if largest is less than SoEast
    {
        Largest = SoWest; // Largest is now equal
        largestName = areaNames[3];
    }
    cout << "The " << largestName << " division had the highest sales this quarter." << endl // display outcome
         << "Their sales were $" << fixed << setprecision(2) << Largest;
}

int main()
{
    double NE, SE, NW, SW; // make a variable for each division

    NE = getSales(); // return function value.
    SE = getSales();
    NW = getSales();
    SW = getSales();

    findHeighest(NE, SE, NW, SW); // run function with the variables as arguments.
}