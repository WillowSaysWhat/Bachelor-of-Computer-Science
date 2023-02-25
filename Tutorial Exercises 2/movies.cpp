/*
Write a program that uses a structure named MovieData to store the following information about a movie:

        Title, Director, Year Released, Running Time (in minutes)

Include a constructor that allows all four of these member data values to be specified at the time a MovieData
variable is created. The program should create two MovieData variables and pass each one in turn to a function
 that displays the information about the movies in a clearly formatted manner. Pass the MovieData variables to
 the display function by value.

Modify the Movie Data program to include two more members that hold the movie's
productions costs and first year revenues.
The constructor should be modified to allow these values to be set.
Modify the function that displays the movie data to display the title, director, release year,
running time, and first year’s profit or loss. Also, improve the program by having the MovieData
variables passed to the display function as constant references.
Demonstrate the structure in a program that asks the user for input.
Output should look like:
Movie Title: <value>
Director: <value>
Release Year: <value>
Run Time: <value>
Profit: $<value>
*/
#include <iostream>
#include <string>

using namespace std;

struct MovieData      // create struct
{                     //
    string title,     // string vars for title and director
        director;     //
    int yearReleased, // int vars for year relesed, runtime, production cost and first year profit and loss
        runningTime, productionCost, revenue;

    MovieData() // automatically excecutes the lines below when object is created
    {
        getline(cin, title); // get the title of the movie

        getline(cin, director); // get the directors name

        cin >> yearReleased >> runningTime >> productionCost >> revenue; // get year, run time, cost, and profit/loss

        cin.ignore(1000, '\n'); // ignores newline
    }
    void displayOutput() const
    {
        cout << "Movie Title: " << title << endl // display variables as requested
             << "Director: " << director << endl
             << "Release Year: " << yearReleased << endl
             << "Run Time: " << runningTime << endl
             << "Profit: $" << revenue - productionCost << endl;
    }
};

int main()
{
    MovieData FirstMovie, SecondMovie; // make 2 objects
    FirstMovie.displayOutput();        // displays the outcome of the 1st movie
    cout << endl;                      // creates a space between each output
    SecondMovie.displayOutput();       // displays second movie
}