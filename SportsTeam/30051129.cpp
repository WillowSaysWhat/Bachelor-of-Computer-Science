#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class Member
{
protected:
	string name, memberPosition, currentAvailability;
public:
	Member (string _name, string _position, string _availability) 
	: name(_name), memberPosition(_position), currentAvailability(_availability){} 
		
};

class Player : public Member
{
protected:
	string team;
	float rating, averageRating;
	vector<float> recentRatings;
public:
	Player(string _name, string _position, string _availability, float rating1, float rating2, float rating3, float rating4, float rating5)
	:Member (_name, _position, _availability)
	{
		recentRatings.push_back(rating1);
		recentRatings.push_back(rating2);
		recentRatings.push_back(rating3);
		recentRatings.push_back(rating4);
		recentRatings.push_back(rating5);
	}
void setRecentRatings(float _rating)
{
	recentRatings.push_back(_rating);
}
void setAverageRating()
{
	float numOfRatings = recentRatings.size();
	for(auto &rating : recentRatings)
	{
		averageRating += rating;
	}
	averageRating = averageRating / numOfRatings;
}
void setTeam(string _team)
{
	this->team = _team;
}

};

class Support : public Member
{
protected:
	string email;
	int phone;
public:
	Support(string name, string position, string availability, string email, int phone)
	: Member (name, position, availability), email(email), phone(phone){}	
};
class Squad
{
protected:
	string teamName = "Australis", headCoach = "Tim The Tool", Analyst = "Jim Bob", Tank, ADC, Jungler, Offlane, Support;
	
	vector<string> positions {"Tank", "ADC", "Jungler", "Offlane", "Support"};

public:
string getName()
{
	return teamName;
}
string getHeadCoach()
{
	return headCoach;
}
string getAnalyst()
{
	return Analyst;
}
	
};
class Match : Squad
{
protected:
	string friendlyTeam, Opponent, date;
public:
	Match (string _friendlyTeam, string _Opponent, string _date) 
	: friendlyTeam(_friendlyTeam), Opponent(_Opponent), date(_date){};

	

	string getFriendlyTeam()
	{
		return friendlyTeam;
	}
	string getOpponent()
	{
		return Opponent;
	}
	string getDate()
	{
		return date;
	}
	
};


// class to display menus
class Menu
{
public:

void mainMenu()
{
	
		cout << "     1. New Match" << endl;
		cout << "     2. Build a Squad" << endl;
		cout << "     3. Post Match Options" << endl;
		cout << "     4. Player Stats" << endl;
		cout << "     5. Team Stats" << endl; 
		cout << "     6. Exit" << endl 
			 << endl;
		cout << "     Make A Selection: ";


}
void PlayerStatsMenu()
{
	cout << "1. View Players By Team."<< endl;
	cout << "2. View Players By Stats." << endl;
	cout << "3. View Players By Position" << endl;
	cout << "4. View Players By Expertise" << endl;
	cout << "5. Exit to Main Menu." << endl;
	cout << endl;
	cout << "PLease Make A Selection: ";
}
void inputFriendlySquad()
{
	cout << "Please Input friendly squad (Australis): ";
	
}
void inputOpponent()
{
	cout << "Please Input Opponent: ";
}
void incorrectInput()
{
	cout << "Error, Does Not Exist. Try Again? (Y/N): ";
}
void inputDate()
{
	cout << "Please input Date of Match(12/09/2023): ";
}

};
// class to display output
class Display : public Menu
{
public:
void banner()
{
	system("cls");
		cout << "          ##########################################" << endl;
		cout << "                         eCoach.io" << endl;
		cout << "           A team management application for eSports" << endl;
		cout << "	         Copyright WillowSaysWhat 2023." << endl;
		cout << "          ##########################################" << endl;	
		cout << endl
			 << endl;
}
void displayMatch(vector<Match> _m, int _i, string _coach, string support)
{
	cout << "Match" << endl 
		 << endl;
	cout << "Team: " << _m[_i].getFriendlyTeam() << " \tOpponent: " << _m[_i].getOpponent() << endl;
	cout << "Head Coach: " << _coach << "Lane Analyst: " <<  endl;
	cout << "Date: " << _m[_i].getDate() << endl;
	cout << "Position: " << support;

	system("pause");
}
void displayPlayerStats(vector<Member> members)
{
	int UserInput;
	
	do
	{
		if((UserInput < 0) && (UserInput > 5)) {continue;}
		
		banner(); // above in Display class
		inputFriendlySquad(); // in Menu class
		cin >> UserInput;
	
		switch (UserInput)
		{
		case 1:
			// by team
			break;
		case 2:
			// by stats
			break;
		case 3:
			// by position
		case 4:
			// by expertise
		default:
			break;
		}

	} while (UserInput == 5);
	
	
}

};

// static functions for each menu

void newMatch(Display display,vector<Squad> squad, vector<Match> match)
{
	string friendly, opponent, date;
	char YesOrNo;
	bool leaveMenu = false;
	do
	{
		display.banner();
		display.inputFriendlySquad();
		cin >> friendly;
		for (size_t i = 0; i < squad.size(); i++)		
		{
			if (squad[i].getName() == friendly)
			{
				display.inputOpponent();
				cin >> opponent;

				display.inputDate();
				cin >> date;


				match.push_back(Match(friendly,opponent, date));
				display.displayMatch(match, i, squad[i].getHeadCoach(), squad[i].getAnalyst());
				break;
			}
			else
			{
				do
				{
					display.incorrectInput();
					cin >> YesOrNo;
					if(toupper('N'))
					{
						leaveMenu = true;
					}
				} while (YesOrNo == toupper('Y') || YesOrNo == toupper('N'));
				

			}
		}


		
	} while (!leaveMenu);
	
}





void loadMembers(vector<Member*> &members) 
	{
		string playerCSV = "players.csv", coachCSV = "coaches.csv",
			   name, position, available, expertise, 
		   	   team, currentRating, averageRating, rating1,
		       rating2, rating3, rating4, rating5; // strings for each input
	
		ifstream fileInput;
		fileInput.open(playerCSV);

		if(fileInput.is_open())
		{
	
			while (fileInput.good()) // pulls data from file using CSV
    	    {
    	        getline(fileInput, name, ',');
        	    getline(fileInput, position, ',');
        	    getline(fileInput, available, ',');
        	    getline(fileInput, expertise, ',');
        	    getline(fileInput, team, ',');
        	    getline(fileInput, currentRating, ',');
        	    getline(fileInput, averageRating, ',');
        	    getline(fileInput, rating1, ',');
        	    getline(fileInput, rating2, ',');
        	    getline(fileInput, rating3, ',');
        	    getline(fileInput, rating4, ',');
        	    getline(fileInput, rating5, '\n');

            	if(fileInput.eof()) break;

				if (position == "Player")
				{
					int lastMember = members.size();
					members.push_back(new Player(name, position, available, stof(rating1), stof(rating2), 
					stof(rating3), stof(rating4), stof(rating5)));
					
					
				}
				else if (position == "Support")
				{
					// members.push_back(new Support())
				}	
                 
				
	
	
        	}
		

		
		}
		else
		{
			cout << "The database does not exist" << endl;
			system("pause");
		}
		fileInput.close();

	
	}


int main()
{
	
	
	
	Display display;

	vector<Squad> Squads;
	vector<Match> Matches;
	vector<Member*> Players;

	loadMembers(Players);
	system("pause");

int UserInput;	
do
{
	display.banner();
	display.mainMenu();
	cin >> UserInput;

	switch (UserInput)
	{
	case 1:
		/* make a new match */
		newMatch(display,Squads, Matches);
		break;
	case 2:
		// generate a squad
		break;

	case 3:
		// after match options like setting player performance, win or loss
		break;

	case 4:
		// display player stats
		break;
	
	case 5:	
		// team stats
		break;

	default:
		break;
	}

} while (UserInput != 6);
	



}