/*
write a program that displays
      A
     BB
    CCC
   DDDD
  EEEEE
 FFFFFF
GGGGGGG
*/
#include <iostream>
#include <string>  // so we can use an array
#include <iomanip> // so we can use setw (so we can set the blank spaces between lines).

using namespace std;

int main()
{
    string Alpha[7] = {"A", "B", "C", "D", "E", "F", "G"}; // initialize the array with all the letters.
    int LenAlpha = 7;                                      // was using size(), however the Code Grade would not accept it
    int setWhiteSpace = LenAlpha;                          // amount of space from the letter decrementing  after each nested loop

    for (int i = 0; i < LenAlpha; i++) // will loop while i is less than the length of the array.
    {
        cout << setw(setWhiteSpace); // sets the spaces between each line(decrements).
        for (int j = 0; j <= i; j++) // loop adds an incrementing amount of letters to each line.
        {
            cout << Alpha[i]; // displays the letter by using array indexing.
        }
        setWhiteSpace--; // minus 1 from this variable.
        cout << endl;    // moves the next iteration to the line below.
    }
    return 0;
}