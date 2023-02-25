#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>



using namespace std;

float CARPET = 5.0, CARPET_INST = 10.0, WOOD = 10.0, WOOD_INST = 15.0, TILED = 15.0, TILED_INST = 20.0;
int CUSTOMERNUMBER = 1;
class Customer
{
private:
    string name, houseNo, street, town, postcode, flooring, phone;
    int customerNum = CUSTOMERNUMBER;
    size_t quoteHistorySize;
    float quote = 0, area = 0, length = 0, width = 0, largestQuote = 0;
    vector<float> quoteHistory = {0, 0, 0, 0, 0};

public:
    Customer() {}

    void setName(string custName) // setters
    {
        this->name = custName;
    }
    void setAddress(string num, string streetName, string townName, string postcodeNum)
    {
        this->houseNo = num;
        this->street = streetName;
        this->town = townName;
        this->postcode = postcodeNum;
    }
    void setPhone(string custPhone)
    {
        this->phone = custPhone;
    }
    void setQuote(float custQuote)
    {
        this->quote = custQuote;
        quoteHistory.push_back(custQuote);
    }
    void ResetQuote(float resetQuote)
    {
        this->quote = resetQuote;
    }
    void ResetQuoteHistory(float &CustQuote)
    {
        quoteHistory.pop_back();
        quoteHistory.push_back(CustQuote);
    }
    void setArea(float custArea)
    {
        this->area = custArea;
    }
    void setLength(float len)
    {
        this->length = len;
    }
    void setWidth(float wid)
    {
        this->width = wid;
    }
    void setCustomerNum(int num)
    {
        this->customerNum = num;
    }
    void setFlooring(string choice)
    {
        this->flooring = choice;
    }
    void setLargestQuote()
    {
        this->largestQuote = quoteHistory[0];
        for (auto i : quoteHistory)
        {
            if (i > largestQuote)
            {
                this->largestQuote = i;
            }
        }
    }
    // GETTERS
    string getName() // getters
    {
        return name;
    }
    string getAddress() // for quick displaying of all string variables (houseNo, Street, town, Postcode)
    {
        return houseNo + " " + street + " " + town + " " + postcode;
    }
    string getHouseNo()
    {
        return houseNo;
    }
    string getStreet()
    {
        return street;
    }
    string getTown()
    {
        return town;
    }
    string getPostcode()
    {
        return postcode;
    }
    string getPhone()
    {
        return phone;
    }
    float getQuote()
    {
        return quote;
    }
    float getQuoteHistory(int index)
    {
        return quoteHistory[index];
    }

    float getArea()
    {
        return area;
    }
    float getLength()
    {
        return length;
    }
    float getWidth()
    {
        return width;
    }
    int getCustomerNumber()
    {
        return customerNum;
    }
    string getFlooring()
    {
        return flooring;
    }
    size_t getquoteHistorySize()
    {
        quoteHistorySize = quoteHistory.size();
        return quoteHistorySize;
    }
    float getLargestQuote()
    {
        return largestQuote;
    }
};

void displayMainMenu()
{
    system("cls"); // clear the terminal

    cout << "\n    ##################################################\n"; // a clean heading that describes the program
    cout << "              Welcome to Flooring.io 0.0.1" << endl;
    cout << "     Flooring.io will help you maintain a professional\n";
    cout << "          customer quoting database on Windows OS.\n";
    cout << "    ##################################################\n";
    cout << endl;
    cout << " What would you like to do?\n\n"; // a prompt for the use to choose a number
    cout << " 1. New Customer" << endl;
    cout << " 2. View Customer" << endl;
    cout << " 3. Make A Quote" << endl;
    cout << " 4. Update Costomer Floor Dimensions" << endl;
    cout << " 5. All Customers Quote History" << endl;
    cout << " 6. Save Customer Details" << endl;
    cout << " 7. Load Customer Details" << endl;
    cout << " 8. Exit" << endl;
    cout << " Enter your choice: "; // prompt for input
}

void newCustomer(Customer &Cust, vector<Customer> &ListOfCustomers)
{
    
    string custName, custSurname, houseNo, street, town, postcode, phone;

    system("cls");
    cout << " ############################\n";
    cout << "      Flooring.io 0.0.1" << endl;
    cout << "   New Customer Input Menu\n";
    cout << " ############################\n";
    cout << "\n First Name: "; // used cin with concatination de to constant getline.ignore bugs.
    cin >> custName;
    cout << " Surname: ";
    cin >> custSurname;
    cout << " phone: ";
    cin >> phone;
    cout << endl;
    cout << " Address \n";

    cout << " house number: ";
    cin >> houseNo;

    cout << " street: ";
    cin.ignore();
    getline(cin, street);

    cout << " Town: ";
    getline(cin, town);

    cout << " Postcode: ";
    cin.ignore();
    getline(cin, postcode);

    custName = custName + " " + custSurname;

    Cust.setName(custName); // set customer details
    Cust.setAddress(houseNo, street, town, postcode);
    Cust.setPhone(phone);

    Cust.setCustomerNum(CUSTOMERNUMBER);
    CUSTOMERNUMBER++;

    ListOfCustomers.push_back(Cust); // put customer object in vector.

    system("cls");
    cout << "\nCustomer Num: " << Cust.getCustomerNumber()
         << "\nname: " << Cust.getName()
         << "\nAddress: " << Cust.getAddress()
         << "\nPhone: " << Cust.getPhone()
         << endl
         << endl;
    // this tells the user to select 'New Quote from the main menu so that all function originate from the switch in main
    cout << "To make a quote, select 3 from the Main Menu \n";
    cout << endl;
    cout << " IMPORTANT: Remeber your Customer's Number.\n";
    cout << endl;
    system("pause");
}

void viewCustomer(vector<Customer> &listOfCustomers)
// displays a customer
// if the customer isn't in the listOfCustomers - asks whether to return to main or try again
// tries again or returns to main using do/while
{
    bool inSearch = false;
    int UserInput_UserNum;
    string UserInput_Name;

    system("cls");

    do
    {
        cout << "#################################\n";
        cout << "  Welcome to Flooring.io 0.0.1\n";
        cout << "     View Customer Details \n";
        cout << "#################################\n";
        cout << endl;
        cout << " Please enter a Customer Number: ";
        cin >> UserInput_UserNum;
        for (Customer &i : listOfCustomers)
        {
            if (UserInput_UserNum == i.getCustomerNumber())
            {

                system("cls");
                cout << endl;
                cout << "        Customer Details" << endl;
                cout << left << setw(10) << left << "Number: " << i.getCustomerNumber() << endl;
                cout << left << setw(10) << left << "Name: " << i.getName() << endl;
                cout << left << setw(10) << left << "Phone: " << i.getPhone() << endl;
                cout << left << setw(10) << left << "Address: " << i.getAddress() << endl;
                cout << endl;
                cout << "        Room Details" << endl;
                cout << left << setw(10) << left << "Length: " << i.getLength() << setw(10) << endl;
                cout << left << setw(10) << left << "Width: " << i.getWidth();
                cout << endl;
                cout << left << setw(10) << left << "Area: " << i.getArea() << endl;
                cout << left << setw(10) << left << "Flooring: " << i.getFlooring() << endl;
                cout << left << setw(10) << left << "Quote:  $" << i.getQuote() << endl;
                cout << endl;
                cout << "        Quote History" << endl;

                for (size_t j = 0; j < 5; j++)
                {

                    cout << "$" << i.getQuoteHistory((i.getquoteHistorySize() - 1) - j) << "  ";
                }

                inSearch = true;
                cout << endl;
                cout << endl;
                system("pause");
                break;
            }
        }
        if (!inSearch)
        {
            char tryAgain;
            cout << "Customer does not exist. Try again (Y/N): ";
            cin >> tryAgain;
            if (toupper(tryAgain) == 'N')
            {
                inSearch = true;
            }
        }
    } while (!inSearch);
}

void makequote(vector<Customer> &listOfCustomers)
{

    int customerNum; // input of customer num
    // bool - this is changed if the customer is not in the vector
    bool InSearch = false, customerIsTrue = false;
    float length, width, area;

    system("cls");
    cout << "######################################################################\n";
    cout << "                       Flooring.io 0.0.1" << endl;
    cout << "                       Make a new quote\n";
    cout << "  Please have a customer number ready. You will be asked to enter\n";
    cout << " the floor dimensions - Length and Width - where you will be given\n";
    cout << "the option to choose Carpeted, Wooden, or Tiled floors. Each option\n";
    cout << "     will display the price of the floor plus installation.\n";
    cout << "               Area is automatically calculated.\n";
    cout << "######################################################################\n";
    cout << endl;

    do // error handling
    {
        cout << "Please input Customer Number: ";
        cin >> customerNum;
        for (Customer &i : listOfCustomers)
        {

            if (customerNum == i.getCustomerNumber())
            {
                customerIsTrue = true;
                system("cls");
                cout << " New Quote\n";
                cout << endl;
                cout << "Customer Number: " << i.getCustomerNumber() << " "
                     << "Name: " << i.getName() << " "
                     << "Phone: " << i.getPhone() << " Address: " << i.getAddress() << endl;

                bool IsCorrect = false;
                char correctInput;
                do // will loop if user says length and width is incorrect
                {
                    cout << endl;
                    cout << "Please input floor Length: ";
                    cin >> length;
                    cout << endl;
                    cout << "Please input floor Width: ";
                    cin >> width;

                    i.setLength(length);
                    i.setWidth(width);
                    area = length * width;
                    i.setArea(area);

                    system("cls");
                    cout << " New Quote\n";
                    cout << endl;
                    cout << "Customer Number: " << i.getCustomerNumber() << " "
                         << "Name: " << i.getName() << " "
                         << "Phone: " << i.getPhone() << " Address: " << i.getAddress() << endl;
                    cout << "Length: " << i.getLength() << endl
                         << "Width: " << i.getWidth() << endl
                         << "Area: " << fixed << setprecision(2) << i.getArea() << endl;
                    cout << endl;
                    cout << "Is this correct? ('n' to input again): ";
                    cin >> correctInput;
                    if (toupper(correctInput) == 'Y')
                    {
                        IsCorrect = true;
                    }

                } while (!IsCorrect);

                IsCorrect = false;
                do
                {

                    float tempQuote;
                    cout << " \nCarpeted floor is: $" << fixed << setprecision(2) << i.getArea() * CARPET << " Plus $" << i.getArea() * CARPET_INST << " installation." << endl;
                    cout << "Wooden floor is: $" << i.getArea() * WOOD << " plus $" << i.getArea() * WOOD_INST << " intallation." << endl;
                    cout << "Tiled floor is: $" << i.getArea() * TILED << " plus $" << i.getArea() * TILED_INST << " installation." << endl;
                    cout << "\nUse c (Carpet), w (Wood), t (tiled) to pick a price: ";
                    cin >> correctInput;

                    if (toupper(correctInput) == 'C')
                    {

                        tempQuote = (i.getArea() * CARPET) + (i.getArea() * CARPET_INST);
                        i.setQuote(tempQuote);
                        i.setFlooring("Carpet");
                        IsCorrect = true;
                    }
                    else if (toupper(correctInput) == 'W')
                    {
                        tempQuote = (i.getArea() * WOOD) + (i.getArea() * WOOD_INST);
                        i.setQuote(tempQuote);
                        i.setFlooring("Wood");
                        IsCorrect = true;
                    }
                    else if (toupper(correctInput) == 'T')
                    {
                        tempQuote = (i.getArea() * TILED) + (tempQuote = i.getArea() * TILED_INST);
                        i.setQuote(tempQuote);
                        i.setFlooring("Tile");
                        IsCorrect = true;
                    }
                    else
                    {
                        cout << "\n Please pick a price - use c, w, t.";
                    }

                } while (!IsCorrect);
                system("cls");
                cout << " New Quote\n";
                cout << endl;
                cout << "Customer Number: " << i.getCustomerNumber() << " "
                     << "Name: " << i.getName() << " "
                     << "Phone: " << i.getPhone() << " Address: " << i.getAddress() << endl;
                cout << "Length: " << i.getLength() << " "
                     << "Width: " << i.getWidth() << " "
                     << "Area: " << i.getArea() << endl;
                cout << i.getFlooring() << " $" << i.getQuote();
                cout << endl
                     << endl;
                InSearch = true;
                system("pause");
                break;
            }
        }
        if (!customerIsTrue)
        {
            char returnToMenu;
            cout << "\nYour customer number is incorrect. Try again (Y/N): "; // your customer number is incorrect
            cin >> returnToMenu;
            if (returnToMenu == 'n' || returnToMenu == 'N')
            {
                InSearch = true;
                break;
            }
        }

    } while (!InSearch);
}

void allCustomerQuoteHistory(vector<Customer> &listOfCustomers)
{
    bool stayOnMenu = true;
    const int VectorSize = listOfCustomers.size();
    Customer* array = new Customer[VectorSize];
    Customer tempCustomer;
    do
    {
        system("cls");
        cout << "###############################\n";
        cout << "    Customer Quote History\n";
        cout << "###############################\n";
        cout << endl;
        cout << "1. View All Customers With Quote History\n";
        cout << "2. View All Customers (Decending From Highest All Time Quote)\n";
        cout << "3. View All Customers (Decending From Highest Recent Quote) \n";
        cout << "4. Main Menu\n"
             << endl;
        cout << "What would you like to see?: ";

        int UserInput = 0;
        cin >> UserInput;

        
        switch (UserInput)
        {
        case 1:
            system("cls");
            cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
            cout << "|" << "Number" << setw(5) << "|" << "Name" << setw(15)<< "|" << "Phone" << setw(10) << "|" << "Address" << setw(45) << "|" << "Quote 1" << setw(10) << "|" << "Quote 2" << setw(10) << "|" << "Quote 3" << setw(10) << "|" << "Quote 4" << setw(10) << "|" << "Quote 5" << "     |";
            cout << endl;

            for (Customer &i : listOfCustomers)
            {
                int QuoteHistorySize = i.getquoteHistorySize() - 1;
                cout << fixed << setprecision(2) << "|" << left << setw(10) << left << i.getCustomerNumber() << "|" << left << setw(18) << left << i.getName() << "|" << left << setw(14)
                     << left << i.getPhone() << "|" << left << setw(5) << left << i.getHouseNo() << left << setw(13) << left << i.getStreet() << left << setw(16)
                     << left << i.getTown() << right << setw(17) << left << i.getPostcode() << "|" << left << setw(16) << left << i.getQuoteHistory(QuoteHistorySize) << "|"
                     << left << setw(16) << left << i.getQuoteHistory(QuoteHistorySize - 1) << "|" << left << setw(16) << left << i.getQuoteHistory(QuoteHistorySize - 2)
                     << "|" << left << setw(16) << left << i.getQuoteHistory(QuoteHistorySize - 3) << "|" << left << setw(12) << left << i.getQuoteHistory(QuoteHistorySize - 4) << "|" << endl;
            }
            cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
            system("pause");
            break;
        case 2:
            for (size_t i = 0; i < listOfCustomers.size(); i++)
            {
                listOfCustomers[i].setLargestQuote();

                array[i] = listOfCustomers[i];
            }

            for (size_t i = 0; i < listOfCustomers.size() - 1; i++)
            {
                for (size_t j = 1; j < listOfCustomers.size(); j++)
                {
                    if (array[i].getLargestQuote() < array[j].getLargestQuote())
                    {
                        tempCustomer = array[i];
                        array[i] = array[j];
                        array[j] = tempCustomer;
                    }
                }
            }
            system("cls");
            cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
            cout << "|" << "Number" << left << setw(5) << "|" << "Name" << left << setw(15) << "|" << "Phone" << left << setw(10)<< "|"<< "Address" << left << setw(45) << "|"<< "Quote 1" << left << setw(10) << "|" << "Quote 2" << left << setw(10) << "|" << "Quote 3" << left << setw(10)  << "|" << "Quote 4" << left << setw(10) << "|" << "Quote 5" << "     |";
            cout << endl;

            for (size_t i = 0; i < VectorSize; i++)
            
            
            {
                int QuoteHistorySize = array[i].getquoteHistorySize() - 1;

                cout << fixed << setprecision(2) << "|" << left << setw(10) << left << array[i].getCustomerNumber() << "|" << left << setw(18) << left << array[i].getName() << "|" << left << setw(14)
                     << left << array[i].getPhone() << "|" << left << setw(5) << left << array[i].getHouseNo() << left << setw(13) << left << array[i].getStreet() << left << setw(16)
                     << left << array[i].getTown() << right << setw(17) << left << array[i].getPostcode() << "|" << left << setw(16) << left << array[i].getQuoteHistory(QuoteHistorySize) << "|"
                     << left << setw(16) << left << array[i].getQuoteHistory(QuoteHistorySize - 1) << "|" << left << setw(16) << left << array[i].getQuoteHistory(QuoteHistorySize - 2)
                     << "|" << left << setw(16) << left << array[i].getQuoteHistory(QuoteHistorySize - 3) << "|" << left << setw(12) << left << array[i].getQuoteHistory(QuoteHistorySize - 4) << "|" << endl;
            }
            cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
            system("pause");

            break;
        case 3:

            for (size_t i = 0; i < listOfCustomers.size(); i++)
            {
                array[i] = listOfCustomers[i];
            }

            for (size_t i = 0; i < listOfCustomers.size() - 1; i++)
            {
                for (size_t j = 1; j < listOfCustomers.size(); j++)
                {
                    if (array[i].getQuote() < array[j].getQuote())
                    {
                        tempCustomer = array[i];
                        array[i] = array[j];
                        array[j] = tempCustomer;
                    }
                }
            }
            system("cls");
            cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
            cout << "|" << "Number" << setw(5) << "|" << "Name" << setw(15) << "|" << "Phone" << setw(10) << "|" << "Address" << setw(45) << "|" << "Quote 1" << setw(10) << "|" << "Quote 2" << setw(10) << "|" << "Quote 3" << setw(10) << "|" << "Quote 4" << setw(10) << "|" << "Quote 5" << "     |";
            cout << endl;

            for (size_t i = 0; i < VectorSize; i++)               
            {
                int QuoteHistorySize = array[i].getquoteHistorySize() - 1;
                cout << fixed << setprecision(2) << "|" << left << setw(10) << left << array[i].getCustomerNumber() << "|" << left << setw(18) << left << array[i].getName() << "|" << left << setw(14)
                     << left << array[i].getPhone() << "|" << left << setw(5) << left << array[i].getHouseNo() << left << setw(13) << left << array[i].getStreet() << left << setw(16)
                     << left << array[i].getTown() << right << setw(17) << left << array[i].getPostcode() << "|" << left << setw(16) << left << array[i].getQuoteHistory(QuoteHistorySize) << "|"
                     << left << setw(16) << left << array[i].getQuoteHistory(QuoteHistorySize - 1) << "|" << left << setw(16) << left << array[i].getQuoteHistory(QuoteHistorySize - 2)
                     << "|" << left << setw(16) << left << array[i].getQuoteHistory(QuoteHistorySize - 3) << "|" << left << setw(12) << left << array[i].getQuoteHistory(QuoteHistorySize - 4) << "|" << endl;
            }
            cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
            system("pause");

            break;
        case 4:
            stayOnMenu = false;
            break;

        default:
            char tryAgain;
            cout << "This is not an option. Try again (Y/N)";
            if (toupper(tryAgain) == 'N')
            {
                stayOnMenu = false;
            }
            break;
        }

    } while (stayOnMenu);
    delete[] array;
}

void floorDimentions(vector<Customer> &listOfCustomers)
// change customer floor dimensions
{
    bool customerIsTrue = false;
    int UserInput = 0;
    float newLength = 0.0, newWidth = 0.0;
do
{
    


    system("cls");
    cout << "\n################################\n";
    cout << "Change Customer floor dimensions\n";
    cout << "     Most Recent Quote\n";
    cout << "\n################################\n";
    cout << endl;
    bool returnToMain = false;

    cout << "Please input Customer Number: ";
    cin >> UserInput;
    for (Customer &i : listOfCustomers)
    {
        if (UserInput == i.getCustomerNumber())
        {
            bool inputIsNumbers = false;
            customerIsTrue = true;
            system("cls");
            cout << "Customer Number: " << i.getCustomerNumber() << " Name: " << i.getName() << " Phone: " << i.getPhone() << endl;
            cout << "Length: " << i.getLength() << "\nWidth: " << i.getWidth() << fixed << setprecision(2) << "\nArea: " << i.getArea() << endl;
            cout << "\nFlooring: " << i.getFlooring() << "\nQuote: $" << i.getQuote() << endl;
            cout << endl;

            cout << "please input Length: ";
            cin >> newLength;
            cout << "Please inout Width: ";
            cin >> newWidth;
            i.setLength(newLength);
            i.setWidth(newWidth);
            i.setArea(newLength * newWidth);

            system("cls");
            cout << "Customer Number: " << i.getCustomerNumber() << " Name: " << i.getName() << " Phone: " << i.getPhone() << endl;
            cout << fixed << setprecision(2) << "Length: " << i.getLength() << " Width: " << i.getWidth() << fixed << setprecision(2) << " Area: " << i.getArea() << endl;
            cout << "Flooring: " << i.getFlooring() << " Quote: $" << i.getQuote() << endl;
            cout << endl;
            cout << "The Customer Chose" << endl
                 << "Flooring " << i.getFlooring() << endl;

            float tempQuote = 0.0;
            if (i.getFlooring() == "Carpet")
            {
                tempQuote = (i.getArea() * CARPET) + (i.getArea() * CARPET_INST);
                i.ResetQuote(tempQuote);
                i.ResetQuoteHistory(tempQuote);
            }
            else if (i.getFlooring() == "Wood")
            {
                tempQuote = (i.getArea() * WOOD) + (i.getArea() * WOOD_INST);
                i.ResetQuote(tempQuote);
                i.ResetQuoteHistory(tempQuote);
            }
            else if (i.getFlooring() == "Tile")
            {
                tempQuote = (i.getArea() * TILED) + (i.getArea() * TILED_INST);
                i.ResetQuote(tempQuote);
                i.ResetQuoteHistory(tempQuote);
            }
            cout << "Quote: $" << fixed << setprecision(2) << i.getQuote() << endl;
            system("pause");
        }
    }
    if (!customerIsTrue) 
    {
        char TryAgain;
        cout << "\nCustomer Does not exist. Try again? (Y/N):";
        cin >> TryAgain;
        if (toupper(TryAgain) == 'N')
        {
            customerIsTrue = true; // ends loop and returns to Main Menu
        }
    }
} while (!customerIsTrue);    
}

// saves all customers to a txt file
// sets up ofstream
// loops over list of customers (vector of objects)
// every iteration (customer) inserts 14 lines of data into txt file
void saveCustomer(vector<Customer> &listOfCustomers)
{
    ofstream saveToFile;

    saveToFile.open("floorscustomer.txt");
    if (saveToFile.is_open())
    {
        for (size_t i = 0; i < listOfCustomers.size(); i++)
        {
            int vectorSize = listOfCustomers[i].getquoteHistorySize() - 1;

            saveToFile << listOfCustomers[i].getCustomerNumber() << "\n";

            saveToFile << listOfCustomers[i].getName() << "\n";

            saveToFile << listOfCustomers[i].getPhone() << "\n";

            saveToFile << listOfCustomers[i].getHouseNo() << "\n";

            saveToFile << listOfCustomers[i].getStreet() << "\n";

            saveToFile << listOfCustomers[i].getTown() << "\n";

            saveToFile << listOfCustomers[i].getPostcode() << "\n";

            saveToFile << listOfCustomers[i].getLength() << "\n";

            saveToFile << listOfCustomers[i].getWidth() << "\n";

            saveToFile << listOfCustomers[i].getFlooring() << "\n";

            // writes the quote history (vector) from the 5 most recent quote (last index, last index - 1, last index -2...)
            saveToFile << listOfCustomers[i].getQuoteHistory(vectorSize - 4) << "\n";

            saveToFile << listOfCustomers[i].getQuoteHistory(vectorSize - 3) << "\n";

            saveToFile << listOfCustomers[i].getQuoteHistory(vectorSize - 2) << "\n";

            saveToFile << listOfCustomers[i].getQuoteHistory(vectorSize - 1) << "\n";

            saveToFile << listOfCustomers[i].getQuoteHistory(vectorSize) << "\n";

            cout << "After save";
        }
        saveToFile.close();
    }
    else
    {
        cout << "\nCould not create file";
    }
}

// this loads customers from a txt file into a list of customers (vector of objects)
// sets up ofstream
// opens file
// loops over list of customers
// every iteration (customer) insets 14 lines of data into the txt file
void loadCustomer(Customer C, vector<Customer> &listOfCustomers)
{
    ifstream loadFromFile;
    loadFromFile.open("floorscustomer.txt");

    vector<string> tempdata; // storage for content
    string content; // data line by line

    if (loadFromFile.is_open())
    {

        // pull all data from file in temp vector
        while (getline(loadFromFile, content))
        {
            tempdata.push_back(content);
        }
    }
    else
    {
        cout << "\nCould not find file";
    }

    loadFromFile.close();

    // sort temp vector into objects

    for (size_t i = 0; i < tempdata.size(); i+=15) 
    { // setting Object variables and changing type to suit (string to int...)
        C.setCustomerNum(stoi(tempdata[i]));
        CUSTOMERNUMBER++; // adds up all the customers in the file to raise the Customer Number to above the number of known customers

        C.setName(tempdata[i + 1]);

        C.setPhone(tempdata[i + 2]);
        C.setAddress(tempdata[i + 3], tempdata[i + 4], tempdata[i + 5], tempdata[i + 6]);
        C.setLength(stof(tempdata[i + 7]));
        C.setWidth(stof(tempdata[i + 8]));
        C.setArea(C.getLength() * C.getWidth());
        C.setFlooring(tempdata[i + 9]);
        C.setQuote(stof(tempdata[i + 10]));
        C.setQuote(stof(tempdata[i + 11]));
        C.setQuote(stof(tempdata[i + 12]));
        C.setQuote(stof(tempdata[i + 13]));
        C.setQuote(stof(tempdata[i + 14]));

        listOfCustomers.push_back(C);
    }
}
// this is the main menu
// initialises object and vector
// uses a while loop unitl number 8 is selected
// exercutes displayMainMenu() for user visuals
// requests user input
// executes swtich
int main()
{
    Customer C;
    vector<Customer> customerObj;
    bool Menu = true;
    int userInput = 0;

    while (Menu)
    {
        system("cls");
        displayMainMenu();
        cin >> userInput;
        switch (userInput)
        {
        case 1:
            newCustomer(C, customerObj); // object is passed only where a new custoemr is made or loaded in
            break;
        case 2:
            viewCustomer(customerObj);
            break;
        case 3:
            makequote(customerObj); // runs the function that makes a quote
            break;
        case 4:
            floorDimentions(customerObj);
            break;
        case 5:
            allCustomerQuoteHistory(customerObj);
            break;
        case 6:
            saveCustomer(customerObj);
            break;
        case 7:
            loadCustomer(C, customerObj);
            break;
        case 8:
            Menu = false;
            break;

        default:
            break;
        }
    }
}
