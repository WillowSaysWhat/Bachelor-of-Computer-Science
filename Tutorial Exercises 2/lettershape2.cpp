// DISCLAIMER: I did this exact method for the traiangle in Letter Shape 1.
//  a very small program that build a triangle using an array and a nested loop

#include <iostream>
#include <iomanip> // library for set whitespace

using namespace std;

void buildTriangle(int triangleHeight, char letters[])
{
    int setWhiteSpace = triangleHeight + 1; // the starting length of the whitesplace +1 for formatting

    for (int i = 0; i < triangleHeight; i++) // loop 7 times startting at 'a'
    {
        cout << setw(setWhiteSpace); // place whitespace
        for (int j = 0; j <= i; j++) // this decides how many letters each line requres by j++ and -- whitespace
        {                            //
            cout << letters[i];      // print letters
        }
        setWhiteSpace--; // minus 1 from here to maintain formatting
        cout << endl;    // next line
    }
}

int main()
{
    int triangleHeight = 7;
    char letters[] = {'a',
                      'b',
                      'c',
                      'd',
                      'e',
                      'f',
                      'g'};                 // letters in example
    buildTriangle(triangleHeight, letters); // run function with args
}