// a simple program to find the smallest number in an array of doubles.
#include <iostream>

using namespace std;

void findTheSmallest(double nums[], int numElements) // function that accepts to args(an array, an integer)
{
    double smallestNum = nums[0];         // a variable that will hold the lowest num
    int smallestIndex = 0;                // a var that holds the lowest number's index place
    for (int i = 0; i < numElements; i++) // loop while i is less than the user's input
    {                                     //
        if (smallestNum > nums[i])        // if the num in the array is less than number in 'smallestNum
        {                                 //
            smallestNum = nums[i];        // number in the array becomes the num in smallsest
            smallestIndex = i;            // samllestindex takes the value of i (iteration)
        }
    }

    cout << "The smallest number is " << smallestNum << " and is found at index " << smallestIndex << endl;
} // displays both smallest number and the index it is in

int main()
{

    int HowManyElements =0; // variable for user to input how many numbers they will place in the array

    cout << "1. How Many numbers you would like to input" << endl // prompts for the user
         << "2. Enter numbers" << endl;
    cin >> HowManyElements;   
         // user input
    double array[HowManyElements]; // initiate array with the user input

    for (int i = 0; i < HowManyElements; i++) // loop for user input into array
    {

        cin >> array[i]; // each loop the user inputs a num into the array
    }

    findTheSmallest(array, HowManyElements); // run function
}