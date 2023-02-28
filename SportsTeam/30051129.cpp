#include <iostream>
#include <vector>

using namespace std;

class Squad
{
protected:
	string teamName = "Australis", headCoach = "Tim The Tool", Analyst = "Jim Bob";
	vector<Member> teamMembers;
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
class Member: Squad
{
protected:
	string name, memberPosition, currentAvailability, expertise;
public:
	Member (string _name, string _memberPosition, string _currentAvailability, string _expertise) 
	: name(_name), memberPosition(_memberPosition), currentAvailability(_currentAvailability), expertise(_expertise){} 
	
	
};
class Player : Member
{
protected:
	string team;
	float rating, averageRating;
	vector<float> recentRatings;
public:
	Player(string _name, string _memberPosition, string _currentAvailability, string _expertise, float _rating)
	:Member (_name,_memberPosition, _currentAvailability, _expertise), rating(_rating){}
void setRecentRatings(float _rating)
{
	recentRatings.push_back(_rating);
}
void setAverageRating()
{
	float numOfRatings = recentRatings.size();
	for( auto &rating : recentRatings)
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
class Support : Member
{
protected:
	string email;
	int phone;
public:
	Support(string _name, string _memberPosition, string _currentAvailability, string _expertise, string _email, int _phone)
	: Member (_name,_memberPosition, _currentAvailability, _expertise), email(_email), phone(_phone){}
	
};
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
class Display
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

	system("pause");
}

};

// static functions for each menu

void newMatch(Display d, Menu m, vector<Squad> squad, vector<Match> match)
{
	string friendly, opponent, date;
	char YesOrNo;
	bool leaveMenu = false;
	do
	{
		d.banner();
		m.inputFriendlySquad();
		cin >> friendly;
		for (size_t i = 0; i < squad.size(); i++)		
		{
			if (squad[i].getName() == friendly)
			{
				m.inputOpponent();
				cin >> opponent;

				m.inputDate();
				cin >> date;


				match.push_back(Match(friendly,opponent, date));
				d.displayMatch(match, i, squad[i].getHeadCoach(), squad[i].getAnalyst());
				break;
			}
			else
			{
				do
				{
					m.incorrectInput();
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


int main()
{
	
	Menu menu;
	Display display;
	Squad Australis;
	
	vector<Member> playersAndStaff;
	vector<Squad> squad = {Australis}; // fix this as i have hard coded 'Australis' in the class
	vector<Match> Matches;

int UserInput;	
do
{
	display.banner();
	menu.mainMenu();
	cin >> UserInput;

	switch (UserInput)
	{
	case 1:
		/* make a new match */
		newMatch(display, menu, squad, Matches);
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