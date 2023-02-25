#include <iostream>
#include <iomanip>

using namespace std;

int amountInput(); // prototyped function

void getScoresAndNames(double scores[], string names[], int amount); // prototyped

void sortList(double scores[], string names[], int amount) // function sorts array
{
    for (size_t i = 0; i <= amount - 1; i++) // bubble sort
    {

        for (size_t j = 0; j <= amount - 1; j++) // sort using pointer notation
        {
            int scoretemp; // make a temporary variable
            string nametemp;
            if (*(scores + i) < *(scores + j)) // if index i is greater than j
            {

                scoretemp = *(scores + j);     // temp holds j
                *(scores + j) = *(scores + i); // i moves to j (so both index is i)
                *(scores + i) = scoretemp;     // temp (j) moves to i

                nametemp = *(names + j); // follows the above formula so that the name stays with the score
                *(names + j) = *(names + i);
                *(names + i) = nametemp;
            }
        }
    }
}

double getAverage(double scores[], int amount) // finds average
{
    double average = 0; // var to add up all indexes
    for (size_t i = 0; i < amount; i++)
    {
        average += *(scores + i); // adds each iteration using pointer notation
    }
    average = average / amount; // return the total / amount of scores
    return average;
}

void displayOutput(double scores[], string names[], int amount, double average) // display data
{
    cout << "Average Score: " << fixed << setprecision(2) << average << endl;
    cout << "The test scores in ascending order are: " << endl;

    for (size_t i = 0; i < amount; i++) // loop over indexes and display

    {
        cout << "Name: " << *(names + i) << " Score: " << fixed << setprecision(2) << *(scores + i) << endl; // displays scores using pointer notation
    }
}
//======main=======================================//
int main()
{
    int amountOfScores = 0; // create int var for user-requested amount
    double average = 0;     // for the average

    amountOfScores = amountInput(); // function to collect user input (below main)
    double scores[amountOfScores];  // initiate array with user input (amountOfScores)
    string names[amountOfScores];
    getScoresAndNames(scores, names, amountOfScores);      // execute function to get scores (below main)
    sortList(scores, names, amountOfScores);               // execute sort function
    average = getAverage(scores, amountOfScores);          // execute fuction that returns the average
    displayOutput(scores, names, amountOfScores, average); // execute display function
}

//================================================//
int amountInput() // placed below main as it is a basic "get" function
{
    int amount = 0;
    cout << "How many scores are you inputing?: ";
    cin >> amount; // get user input

    return amount; // return user input
}
void getScoresAndNames(double scores[], string names[], int amount) // get scores
{
    cout << "please input names and scores: ";
    for (size_t i = 0; i < amount; i++) // loop through array and record user input
    {
        cin >> *(names + i);  // added names
        cin >> *(scores + i); // use pointer notation
    }
}