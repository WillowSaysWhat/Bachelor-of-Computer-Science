#include <iostream>

using namespace std;

bool outcome(int lotteryNums[], int &listLength, int &userN) // return true of false - whether nums are in list
{
    bool thereOrNot = false; // bool var for answer - default is false

    for (size_t i = 0; i <= listLength - 1; i++) // bubble sort
    {

        for (size_t j = 0; j <= listLength - 1; j++) // loop and nest loop at separate numbers
        {                                            //
            int temp;                                // temp var for holding so we can swap two numbers in two indexes
                                                     //
            if (lotteryNums[i] < lotteryNums[j])     // if left int is bigger than right
            {

                temp = lotteryNums[j];           // add left int here
                lotteryNums[j] = lotteryNums[i]; // place right int into left position
                lotteryNums[i] = temp;           // place right int (inside temp) into left position
            }
        }
    }
    // for (size_t i = 0; i < listLength; i++)
    // {
    //     cout << lotteryNums[i] << " ";
    // }

    // binary search: Note - bubble sort is from highest to lowest
    int first = 0, last = listLength, mid = 0; // variables for binary search

    while (!thereOrNot && first <= last) // binary search
    {
        mid = (first + last) / 2;      // get the centre of the list
        if (lotteryNums[mid] == userN) // if mid is correct
        {
            thereOrNot = true; // make it true
        }
        else if (lotteryNums[mid] > userN) // else if it is not mid
            last = mid - 1;                // minus 1 from mid
        else
            first = mid + 1; // else plus 1 to mid
    }
    return thereOrNot; // return answer to main
}

void display(bool &wonOrNot) // display for user
{
    if (wonOrNot)                                // if bool is true
    {                                            //
        cout << "Congratulations, you have won"; // display this
    }                                            //
    if (!wonOrNot)                               // id bool is false
    {                                            //
        cout << "Better luck next time";         // display this
    }
}

int main()
{
    int lotteryNums[] = {13579, 26791, 55555, 33445, 93121,
                         62483, 77777, 79422, 85647, 26792},       // number array
        listLength = sizeof(lotteryNums) / sizeof(lotteryNums[0]), // length of arry
        userNumbers;                                               // user lottery numbers
    bool wonOrNot;                                                 // empty bool var

    // cout << "input your lottery numbers: "; // prompt
    cin >> userNumbers; // user input

    wonOrNot = outcome(lotteryNums, listLength, userNumbers); // executing function with bool return
    display(wonOrNot);                                        // executing function with bool arg
}