#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

class baseball // class that contains everything
{
private:
    vector<string> teams, winners;       // vectors to contian both fine input
    string userTeam;                     // string vars to hold the user's team
    int userpicked = 0, yourTeamWon = 0; // int vars to hold the usersteam number & the num of times user team won

public:
    baseball() // default constructor that automatically gets file data and display team choices
    {
        getFileData();
        displayTeams();
    }
    void getFileData();  // gets data from both files (Teams.txt) & (WorldSeriesWinners.txt)
    void displayTeams(); // displays teams for user to choose
    void getTeam();      // request input
    void timesWon();     // how many times they won
    void DisplayUserTeamAndWins();
};

void baseball::getFileData() // gets data from both files
{
    fstream infile1, infile2; // an fstream for each file
    string x;                 // string var to hold each line

    infile1.open("Teams.txt");              // open file
    infile2.open("WorldSeriesWinners.txt"); // open file

    if (infile1.is_open())          // if it is there...
    {                               //
        while (getline(infile1, x)) // gets file data line by line into x
        {                           //
            teams.push_back(x);     // puts x into the last index
        }                           //
        infile1.close();            // closes file
    }
    else                                  // otherwise
    {                                     //
        cout << "there is no file there"; // warns user
    }

    if (infile2.is_open()) // if file is present
    {
        while (getline(infile2, x)) // as above
        {                           //
            winners.push_back(x);   // places x in vector
        }                           //
        infile2.close();            // closes second file
    }
    else // otherwise
    {
        cout << "there is no file here"; // warns user
    }
}
void baseball::displayTeams() // displays a menu for the user
{
    int lengthOfTeams = teams.size(), count = 1; // var with the int value of the length of vector
    cout << endl;                                // formatting
    for (size_t i = 0; i < lengthOfTeams; i++)   // loops for the length of teams
    {
        cout << setw(2) << right << count << ". " << setw(1) << teams[i] << endl; // displays the teams

        count++; // adds 1 to count (used to number each team)
    }
}
void baseball::getTeam() // ask for input
{
    cout << "\nFind out how many times your team has won The World Series (1950 - 2014)" << endl;
    cout << "\nPlease choose your team from the list above by number (1-29): \n";
    cin >> userpicked; // int value of team

    userTeam = teams[userpicked - 1]; // gets the string value of user's team
}
void baseball::timesWon() // sums up the wins
{

    for (size_t i = 0; i < winners.size(); i++) // loops for the length of vector - winners
    {                                           //
                                                //
        if (userTeam == winners[i])             // if the string value of userTeam is in the vector
        {                                       //
            yourTeamWon++;                      // add 1 to variable
        }
    }
}
void baseball::DisplayUserTeamAndWins() // displays out come
{
    cout << "The team " << userTeam << " has won the world series " << yourTeamWon << " times";
}

int main()
{
    baseball yourTeam;  // initiate object
    yourTeam.getTeam(); // run funtions in order to get result
    yourTeam.timesWon();
    yourTeam.DisplayUserTeamAndWins();
}