// program that displays the match that has the highest ticket sales
#include <iostream>
#include <string>

using namespace std;

struct StadiumData    // structure names as requested
{                     //
                      //
    string matchName, // strings names as required.
        playerName1, playerName2,
        slot;

    int ticketsBooked, // integer variables for tickets booked and ticket price
        priceTicket;

    StadiumData(string match, string player1, string player2, string slot, int booked, int price)
    { // Default constructor that places values into structure's variables
        this->matchName = match;
        this->playerName1 = player1;
        this->playerName2 = player2;
        this->slot = slot;
        this->ticketsBooked = booked;
        this->priceTicket = price;
    }
};

void displayMatches(StadiumData &match1, StadiumData &match2, StadiumData &match3)
{ // displays the ticket sales for all 3 matches by calling in each object
    cout << "Match 1 has sold " << match1.ticketsBooked << " tickets" << endl
         << "Match 2 has sold " << match2.ticketsBooked << " tickets" << endl
         << "Match 3 has sold " << match3.ticketsBooked << " tickets" << endl
         << endl;
}

void DisplayBestMatch(StadiumData &BestMatch, int total)
{ // Displays information on the highest selling match and - on the last line - total ticket sales of all matches
    cout << "Match " << BestMatch.matchName[6] << " sold the most tickets with " << BestMatch.ticketsBooked << " here is that matches details:" << endl
         // labeling match "number" by using string[index]
         << "Match Name: " << BestMatch.matchName << endl
         << "Player on the Left: " << BestMatch.playerName1 << endl
         << "Player on the Right: " << BestMatch.playerName2 << endl
         << "Playing Time: " << BestMatch.slot << endl
         << "Tickets booked: " << BestMatch.ticketsBooked << " Out of 500" << endl
         << "Price of entry ticket: " << BestMatch.priceTicket << endl
         << endl
         << "Total tickets sold: " << total; // the total of all matches.
}
void getHeighestMatch(StadiumData &m1, StadiumData &m2, StadiumData &m3)
{
    int totalTickets = m1.ticketsBooked + m2.ticketsBooked + m3.ticketsBooked; // total of all matches
    if ((m1.ticketsBooked > m2.ticketsBooked) && (m1.ticketsBooked > m3.ticketsBooked))
    {                                       // if match 2 is greater than match 2 and 3
        DisplayBestMatch(m1, totalTickets); // call function with match 1 object and total
    }
    else if ((m2.ticketsBooked > m1.ticketsBooked) && (m2.ticketsBooked > m3.ticketsBooked))
    {                                       // if match 2 is greater than match 1 and match 3
        DisplayBestMatch(m2, totalTickets); // call function with match 2 object and total
    }
    if ((m3.ticketsBooked > m1.ticketsBooked) && (m3.ticketsBooked > m2.ticketsBooked))
    {                                       // if match 3 is greater than match 1 and match 2
        DisplayBestMatch(m3, totalTickets); // call function with match 3 object and total
    }
}

int main()
{

    StadiumData match1("Match 1", "Jim", "Tony", "Afternoon", 245, 40); // create all 3 objects
    StadiumData match2("Match 2", "Bob", "Ethan", "Morning", 129, 60);
    StadiumData match3("Match 3", "James", "Sam", "Evening", 499, 80);

    displayMatches(match1, match2, match3); // call functions with the 3 match objects
    getHeighestMatch(match1, match2, match3);
}