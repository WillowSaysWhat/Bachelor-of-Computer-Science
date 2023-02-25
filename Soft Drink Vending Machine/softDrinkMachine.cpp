#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int NumOfChoices = 5; // the number of products (flavours) available

class softDrinkMachine
{
private:
    string drinkNames[NumOfChoices] = {"Cola",
                                       "Root Bear",
                                       "Orange Soda",
                                       "Grape Soda",
                                       "Bottled Water"}; // names of drinks

    double cost[NumOfChoices] = {1.00, 1.00, 1.00, 1.00, 1.50}; // prices of drinks
    int stockCount[NumOfChoices] = {3, 20, 20, 20, 20};         // stock count

    double insertedMoney = 0.0, change = 0, dailyTotal = 0; // variables for money inserted, and change returned.
    int drinkChoice = 0;                                    // drink choice number
    bool endNow = true;                                     // bool to end program (dailyReport)

    // prototypes
    void inputMoney();  // requeat user to insert money
    void changeStock(); // changes stock value by -1
    void dailyReport(); // displays daily report

public:
    softDrinkMachine() // default constructor
    {
        while (endNow) // loop creates a continuous running menu until exit is requested
        {
            displayChoices();
            buyDrinks();
            dailyReport();
            checkForChange();
        }
    }
    void displayChoices();        // displays menu
    void buyDrinks();             // request user to pick a drink
    string soldOut(size_t drink); // takes arg from displaychoices (look for on line 61 ****) to display 'Sold Out'
    void checkForChange();        // returns change to user
};

//========== private funcitons ==========
void softDrinkMachine::inputMoney()        // request to insert money
{                                          //
    cout << "Please insert Your Money: $"; //
    cin >> insertedMoney;                  // input value into variable
}
void softDrinkMachine::changeStock() // changes stock value as drinks are bought
{                                    //
    stockCount[drinkChoice] -= 1;    // minus stock by 1
}

//========== public functions ==========
void softDrinkMachine::displayChoices()
{

    cout
        << "\n\t*** Soft Drinks ***\n"        // heading
        << endl;                              //
    for (size_t i = 0; i < NumOfChoices; i++) // loops over arrays to create a menu
    {
        string soldOutOrNot = soldOut(i);                                             // stores return val from soldOut function ****
        cout << "\t" << i << " " << left << setw(15) << left << drinkNames[i] << left // displys menu
             << "$" << right << fixed << setprecision(2) << cost[i] << "  " << soldOutOrNot << endl;
    }
    cout << endl;
}

void softDrinkMachine::buyDrinks() // gets money and requests selection
{
    bool notINstock = true;                  // bool to end loop
    inputMoney();                            // asks for user to insert money via function
    cout << "Pick your drink choice(0-4): "; // prompt to input choice
    cin >> drinkChoice;                      // user input

    while (notINstock)
    {
        if (stockCount[drinkChoice] == 0) // checks that stock value is 0
        {
            cout << "SOLD OUT\n";                    // prompts user that drink stock is 0
            cout << "Pick your drink choice(0-4): "; // prompt to input choice
            cin >> drinkChoice;                      // gets user input
            cout << endl;                            // formatting
        }
        else
        {
            notINstock = false;              // changes bool to false so loop ends
            changeStock();                   // changes stock value by -1 through this function
            dailyTotal += cost[drinkChoice]; // adds price of drink to total daily profits
        }
    }
}
string softDrinkMachine::soldOut(size_t drink) // places 'sold out' sign on display in displayChoices function
{
    string output;                                                                         // var to hold return value
    if ((stockCount[drinkChoice] == 0) and (drinkNames[drink] == drinkNames[drinkChoice])) // if chosen drink stock is 0
    {
        output = "Sold Out";         // output is equal to sold out
        stockCount[drinkChoice] = 0; // make sure that stock value doesn't drop into -ve numbers. (just a fail safe)
    }
    else
    {
        output = " "; // otherwise output is equal to a black string
    }                 //
    return output;    // return string for display in displayChoices function
}
void softDrinkMachine::checkForChange() // checks for change
{

    if ((insertedMoney - cost[drinkChoice]) >= 0)                                         // if the value of is not 0 after minusing cost
    {                                                                                     //
        cout << "\t     Your change is: $" << (insertedMoney - cost[drinkChoice]) << endl // print change
             << endl;
    }
}
void softDrinkMachine::dailyReport() // displays daily report and option to turn off machine
{
    if (drinkChoice == 5) // if the user chooses option 5 (hidden)
    {
        string password = "admin1234", input; // var for password

        cout << "Password: "; // prompt for user to enter passwaord
        cin >> input;         // user input

        if (input == password) // if the password is correct
        {
            cout << "\nPrinting Daily Report Now...\n"; // display
            cout << endl;
            system("pause"); // asks user to press enter

            cout << "\n\t ***Daily Report***\n1"; // prints report
            cout << endl;
            cout << left << setw(15) << left << "\t  Product" << left << "" << right << "Stock\n"; // column headings
            cout << endl;

            for (size_t i = 0; i < NumOfChoices; i++) // body of report
            {

                cout << "\t"
                     << " "
                     << " " << left << setw(15) << left << drinkNames[i] << left
                     << "" << right << stockCount[i] << endl;
            }
            cout << "\n\t  Daily Total $" << dailyTotal << "\n"
                 << endl;

            // this is the exit option for the administrator
            char yesORno;                                                 // var for user input
            cout << "Would you like to shut down the Vending Machine?: "; // display prmpt
            cin >> yesORno;                                               // user input

            if (yesORno == 'y' or yesORno == 'Y') // ifthe admin says yes to exiting
            {
                endNow = false; // bool becomes false and the loop in the default constructor stops and the program is ends.
            }
        }
    }
}

int main()
{

    softDrinkMachine one; // initiates object

    //catch admin password when wrong - I get an infinite loop right now
}