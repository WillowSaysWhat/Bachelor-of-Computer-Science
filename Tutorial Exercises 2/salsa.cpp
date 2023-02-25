// a simple program that uses a class to report the number of salsa jars sold in a month.
#include <iostream>
#include <iomanip> // set white space

using namespace std;

class salsa
{
private:
    int numSalsas = 5, // the number of flavours
        total = 0,
        salsaSales[5]; // array to hold user input

    const string salsaNames[5] = {"mild", "medium", "sweet", "hot", "zesty"}; // constant with the names of the salsas

    string low, // variable to hold the names of the lowest
        high;   // and highest

public:
    salsa() // default constructor that executes each function sequencially
    {
        setSalsaAmount();
        setTotal();
        setLow();
        setHigh();
        display();
    }
    void setSalsaAmount(); // prototypes
    void setTotal();
    void setLow();
    void setHigh();
    void display();
};
// =========================================================================//
// functions

void salsa::setSalsaAmount() // collects user input
{
    cout << "Please input number of jars for each flavour:" << endl;
    for (int i = 0; i < numSalsas; i++) // loop the length of the array (5)
    {                                   //
        cin >> salsaSales[i];           // requests input and places each iteration into array at [i] index
    }
}
void salsa::setTotal() // sums up all user input to get total jars sold
{

    for (int i = 0; i < numSalsas; i++) // loops the length of the array (5)
    {                                   //
        total += salsaSales[i];         // add [i] to the value of total
    }
}
void salsa::setLow() // finds the flavour with the lowest sales
{
    int lowest = 99999;                 // variable to hold the lowest num
    for (int i = 0; i < numSalsas; i++) // loops over the array
    {                                   //
        if (lowest > salsaSales[i])     // if the value of lowest is bigger than index [i]
        {                               //
            lowest = salsaSales[i];     // then lowest becomes that index value (int value)
            low = salsaNames[i];        // then low becomes that index value (string value)
        }
    }
}
void salsa::setHigh() // find the highest sales
{
    int highest = 0;                    // variable to hold the highest value
    for (int i = 0; i < numSalsas; i++) // loop over length of array
    {                                   //
        if (highest < salsaSales[i])    // if highest is smaller than index
        {                               //
            highest = salsaSales[i];    // index becomes variable value
            high = salsaNames[i];       // index becomes variable value
        }
    }
}
void salsa::display() // display
{

    cout << "\n Salsa Sales Report\n\n"; // title and headings
    cout << "Name       Jars Sold \n";
    cout << "____________________ \n";

    for (int i = 0; i < numSalsas; i++) // loop length of array
    {
        cout << setw(6) << left << salsaNames[i] << setw(11) << right << salsaSales[i] << endl; // print flavours
                                                                                                // and amounts
    }                                                                                           // using set whitespace and left align

    cout << "\nTotal Sales: " << total << endl // display total, top and bottom earner
         << "High Seller: " << high << endl
         << "Low Seller : " << low;
}
//================================================================================//

int main()
{

    salsa salsa; // create object.
}