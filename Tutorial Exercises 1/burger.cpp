// A burger stall sells four types of burger: Kids $2.50, Hamburger $3.50, Cheeseburger $4.20, Cheese and Bacon burger $5.00. Write a program that asks the user to input how many of each burger was sold that day, then display the total sales for that day. Display the value with two decimal places.
// Output should look like:
// Total sales for the day $ <value>

#include <iostream> // use in/out stream library
#include <iomanip>  // use in/out manipulation library (fixed << setprecision(2))

using namespace std;

int main()
{
    float kids = 2.50;           // float that holds the price of the kids meal
    float hamburger = 3.50;      // hamburger price
    float cheeseburger = 4.20;   // cheeseburger price
    float cheeseAndBacon = 5.00; // cheese and bacon burger price

    int amountKids;           // int that holds the amount of kids meals sold
    int amountHamburgers;     // holds amount of hamburgers
    int amountCheeseburgers;  // holds the amount of cheeseburgers
    int amountCheeseAndBacon; // holds the amount of cheese and bacon burgers

    cin >> amountKids >> amountHamburgers >>
        amountCheeseburgers >> amountCheeseAndBacon; // input to the three variables - simplified for Code Grade

    cout << "Total sales for the day $" << fixed << setprecision(2) // display as shown in line (3) set to 2 decimal places
         << (kids * amountKids) + (hamburger * amountHamburgers) +
                (cheeseburger * amountCheeseburgers) +
                (cheeseAndBacon * amountCheeseAndBacon); // displaying the total without using a variable.

    return 0; // returning an int because it is an int function
}