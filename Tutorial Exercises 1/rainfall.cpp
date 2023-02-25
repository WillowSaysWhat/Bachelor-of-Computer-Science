#include <iostream>
#include <fstream> // use this library to manipulate files
#include <string>  // use this to be able to convert string to float
#include <vector>  // use this to make vectors

using namespace std;

void getRainfall() // utilising a function other than main.
{
    fstream Data;        // making a fstream data type
    string fileName;     // this allows code grade to input all files
    cin >> fileName;     // code grade's method of input
    Data.open(fileName); // opening fstream

    if (Data.is_open()) // if successful
    {
        string x;               // a string var to temporarily hold each line from the fstream
        vector<string> allData; // a vector to hold all the data
        int count = 0;          // a way to get the length of the vector so we can find the average later.

        while (Data >> x) // while there is data coming out of the fstream
        {

            allData.push_back(x); // place each iteration into vector

            count++; // count that index
        }

        float addingRainfall = 0, avgRainfall;  // make a var to add up all numbers, a container for the averge
                                                //
        for (short i = 2; i < count; i++)       // a loop to add up all the numbers. it starts as index 2 so it misses the words.
        {                                       //
            addingRainfall += stof(allData[i]); // adds the converted strings(floats) together.
        }

        avgRainfall = addingRainfall / (count - 2); // finds the average of the added nums (takes the length of only the numbers)
        // displays correctly
        cout << "During the months of " << allData[0] << "-" << allData[1] << ", the total rainfall was "
             << addingRainfall << " inches, and the average monthly rainfall was " << avgRainfall << " inches.";
    }
    else // if there is no file found.
    {
        cout << "there is no file";
    }
}

int main()
{
    getRainfall(); // execute the function above
}
