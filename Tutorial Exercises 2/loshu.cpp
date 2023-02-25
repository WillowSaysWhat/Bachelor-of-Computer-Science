#include <iostream>

using namespace std;

class loshu
{
private:
    int addsToIoshu = 15, rowsAndCols = 3, // variables to hold the number of rows and cols, and the magic 15
        input[3][3];                       // 2d array 3x3
    bool magic = true;                     // boolean for whether it is a magic square

public:
    loshu() // default constructor that gets input and checks it.
    {
        getInput();
        checkInput();
    }

    void getInput(); // prototypes
    void checkInput();

    void displayMagicBox();
    void checkAndDisplay();
};

void loshu::getInput() // uses a nested loop to get input from user
{
    cout << "Please enter your 9 numbers: " << endl;
    for (size_t i = 0; i < rowsAndCols; i++)     // loops through the 3 arrays
    {                                            //
        for (size_t j = 0; j < rowsAndCols; j++) // loop through the 9 indexes in all three arrays - loops 3 times then return to outer loop
        {                                        //
            cin >> input[i][j];                  // user input into each index
        }
    }
}
void loshu::checkInput()
{
    int checks[4]; // array to hold addition

    // rows
    for (size_t i = 0; i < rowsAndCols; i++) // gets the first coord in matrix (i,0-2)
    {                                        // rows                                                 //cols
        if ((input[i][0] + input[i][1] + input[i][2]) != addsToIoshu or (checks[1] = input[0][i] + input[1][i] + input[2][i]) != 15)
        {                  // if row or col [i] don't add up to 15
            magic = false; // it is not a magic square
            break;         // don't check anymore rows or cols
        }
    }
    // diagonals

    if ((input[0][0] + input[1][1] + input[2][2] != 15) or (input[2][0] + input[1][1] + input[0][2] != 15))
    {                  // if diagonal 1 or 2 don't add up to 15
        magic = false; // it is not a magic square
    }
}

void loshu::displayMagicBox()
{

    cout << "for numbers ";
    for (size_t i = 0; i < rowsAndCols; i++) // nested loop to print out all number in a line
    {
        for (size_t j = 0; j < rowsAndCols; j++)
        {
            cout << input[i][j] << " ";
        }
    }
    cout << "as in the image:" << endl
         << endl; // finishes sentence

    for (size_t i = 0; i < rowsAndCols; i++) // nested loop that displays numbers in square format
    {
        for (size_t j = 0; j < rowsAndCols; j++)
        {
            cout << input[i][j] << " ";
        }
        cout << endl; // this is the diference from the first nested loop above
    }                 //
    cout << endl;     // space in formatting
                      //
}
void loshu::checkAndDisplay()
{

    {
        for (size_t i = 0; i < rowsAndCols; i++)
        {
            for (size_t j = 0; j < rowsAndCols; j++)
            {
                for (size_t k = 0; k < rowsAndCols; k++)
                {
                    int temp;
                    if (input[i][j] < input[i][k])
                    {
                        temp = input[i][k];        // add left int here
                        input[i][k] = input[i][j]; // place right int into left position
                        input[i][j] = temp;
                    }
                }
            }
        }
    }
    int oneToNine = 1, count;
    for (size_t i = 0; i < rowsAndCols; i++)
    {
        for (size_t j = 0; j < rowsAndCols; j++)
        {
            if (input[i][j] != oneToNine)
            {
                magic = false;
            }
        }
    }

    if (magic == true) // if variable 'magic' is equal to true
    {
        cout << "It is a magic square";
    }
    else if (magic == false) // if variable is equal to false.
    {
        cout << "It is not a magic square";
    }
}

int main()
{
    loshu game1;             // make object
    game1.displayMagicBox(); // display your input
}