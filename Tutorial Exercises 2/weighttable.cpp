
#include <iostream>
#include <iomanip>

using namespace std;

float toPounds(float imperialTons) // function named toPounds
{

    return (imperialTons * 2240.0); // converts imperial ton to pounds and returns to main
}

float toKilograms(float imperialTons) // function named toKilograms
{
    return (imperialTons * 1016.05); // converts imperial ton to kilos and returns to main
}

int main()
{
    float tons = 0, kilos, pounds; // make 3 floats to hold tons and the returned values from both functios

    cout << "|--------------------------------|\n" // displays the header of the table
         << "|" << left << setw(10) << left << "Tons"
         << "|" << left << setw(10) << left << "Pounds"
         << left << "|" << setw(10) << "Kilograms"
         << "|\n"
         << "|--------------------------------|" << endl;

    while (tons < 20.0) // loop while tons is not equal to 20
    {
        tons += 2.0;               // raises the value of tons by 2 every iteration
        pounds = toPounds(tons);   // runs toPounds funtion with the value of tons
        kilos = toKilograms(tons); // runs toKilograms function with the value of tons

        cout << "|" << left << setw(10) << left << tons << "|" // displays the middle of the table with the
             << left << setw(10) << left << pounds             // results of each call of the function.
             << left << "|" << setw(10) << kilos << "|" << endl;
    }
    cout << "|--------------------------------|"; // displays the bottom of the table
}
