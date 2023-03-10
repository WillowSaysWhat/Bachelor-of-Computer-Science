#include <iostream>
#include <vector>
#include <fstream>
#include <limits> // cin.ignore (numeric_limits<streamsize>)
#include <iomanip>
#include <cctype> // toupper

using namespace std;


class Member
{
protected:
	string fname, sname, memberPosition, currentAvailability, email, expertise;
public:
	Member (const string _fname,const string _sname, const string _availability, const string _expertise) 
	: fname(_fname), sname(_sname), currentAvailability(_availability), expertise(_expertise) {}

virtual void SetMemberPosition() = 0;

void setCurrentAvail(string _avail) {this->currentAvailability =_avail;}
string getName() {return fname + " " + sname;}
string getMemberPos() {return memberPosition;}	
string getCurrentAvail(){return currentAvailability;}
string getExpertise() {return expertise;}
string getEmail() {return email;}
string saveFirstNameToFile() {return fname;}
string saveSecNameToFile() {return sname;}
};

class Player : public Member
{
private:
	
	float rating, averageRating, vectorsize;
	vector<float> recentRatings;
public:
	Player(const string _fname, const string _sname, const string _availability, 
		   const float rating1, const float rating2, const float rating3, const float rating4, 
		   const float rating5, const string _expertise)
	:Member (_fname, _sname, _availability, _expertise)
	{
		recentRatings.push_back(rating1); recentRatings.push_back(rating2); recentRatings.push_back(rating3); 
		recentRatings.push_back(rating4); recentRatings.push_back(rating5);
		SetMemberPosition(); setAverageRating(); setEmail();
	}
void SetMemberPosition() {this->memberPosition = "Player";}
void setRecentRatings(float _rating) {recentRatings.push_back(_rating); this->rating = _rating;}
void setEmail(){this->email = fname+"@player.esports.com";}
void setAverageRating()
{
	vectorsize = recentRatings.size();
	for (auto &r :recentRatings)
	{
		averageRating += r;
	}
	averageRating = averageRating / vectorsize;
}

float getAverageRating() {return averageRating;}
float getRecentRating(size_t index) {return recentRatings[index];}
size_t getVectorLength() {return recentRatings.size();}
float getLengthRecenRatings()
{
	vectorsize = recentRatings.size();
	return vectorsize;
}

};

class Support : public Member
{
protected:
	string phone;
public://(fname, sname, available, phone, expertise)
	Support(const string _fname, const string _sname, const string _availability, const string _phone, const string _expertise)
	: Member (_fname, _sname, _availability, _expertise), phone(_phone){SetMemberPosition(); setEmail();}

void SetMemberPosition(){this->memberPosition = "Support";}
void setEmail(){this->email = fname+"@support.esports.com";}
string getPhone() {return phone;}
};
class Squad
{
protected:
	string squadName = "No Name", headCoach = "Position Empty", headCoachPhone, headcoachEmail, Analyst = "Position Empty", analystPhone, analystEmail, Tank = "Position Empty", ADC= "Position Empty", Jungler= "Position Empty", Offlane= "Position Empty", Support= "Position Empty";
	float SquadRating = 0.0;
	
	

public:
Squad(string &_friendlyTeam, string &_coach, string &_analyst, string &_tank, string &_ADC, string &_jungler, string &_offlane, string &_support)
	: squadName(_friendlyTeam), headCoach(_coach), Analyst(_analyst), Tank(_tank), ADC(_ADC), Jungler(_jungler), Offlane(_offlane), Support(_support){}; 
//setters
void setSquadRating(float average) 
	{
		this->SquadRating = average;
	}
void setSquadName(string &_squad) {this->squadName = _squad;}
void setCoach(string &_coach) {this->headCoach = _coach;}
void setAnalyst(string &_analyst) {this->Analyst = _analyst;}
void setTank(string &_tank) {this->Tank = _tank;}
void setADC(string &_ADC) {this->ADC = _ADC;}
void setJungler(string &_jungler) {this->Jungler = _jungler;}
void setOfflane(string &_offlane) {this->Offlane = _offlane;}
void setSupprt(string &_support) {this ->Support = _support;}
void setAnalystPhone(string _phone) {this->analystPhone = _phone;}
void setAnalystEmail(string _email) {this->analystEmail = _email;} 
void setheadCoachPhone(string _phone) {this->headCoachPhone = _phone;}
void setheadCoachEmail(string _email) {this->headcoachEmail = _email;}
//getters
string getSquadName() {return squadName;}
string getHeadCoach() {return headCoach;}
string getAnalyst() {return Analyst;}
string getTank() {return Tank;}
string getADC() {return ADC;}
string getJungler() {return Jungler;}
string getOfflane() {return Offlane;}
string getSupport() {return Support;}
float getSquadRating() {return SquadRating;}
	
};
class Match : public Squad
{
protected:
	string Opponent, Outcome = "N/A";
public:
	Match (string _friendlyTeam, string _Opponent, string _coach, string _analyst, string _tank, string _ADC, string _jungler, string _offlane, string _support) 
	: Squad(_friendlyTeam, _coach, _analyst,_tank, _ADC, _jungler, _offlane, _support), Opponent(_Opponent){};
	//setters
	void setOpponent(string &opponent) {this->Opponent = opponent;}
	void setOutcome(string &_outcome) {this->Outcome = _outcome;}
	//getters
	string getOpponent() {return Opponent;}
	string getOutcome() {return Outcome;}
	
	
};


// class to display menus
class Menu
{
public:

void mainMenu()
{
	
	cout << "     1. New Player/Staff" << endl;
	cout << "     2. New Match" << endl;
	cout << "     3. Post Match" << endl;
	cout << "     4. Change Availability" << endl;
	cout << "     5. Player Stats" << endl;
	cout << "     6. Support Staff Roster" << endl;
	cout << "     7. Match History" << endl; 
	cout << "     0. Exit" << endl 
			 << endl;
	cout << "     Make A Selection: ";


}
void NewPlayerAndStaffMenu()
{
	cout << "1. New Player." <<endl;
	cout << "2. New Staff Member." << endl;
	cout << "0. Exit," << endl;
	cout << endl;
	cout << "Please Make A Selection: ";
}
void PlayerStatsMenu() 
{
	cout << "1. View Players By Stats." << endl;
	cout << "2. View Players By Expertise" << endl;
	cout << "0. Exit to Main Menu." << endl;
	cout << endl;
	cout << "Please Make A Selection: ";
}
void matchStatsMenu()
{
	cout << "1. Sort Matches By Rating." << endl;
	cout << "2. Sort Matches By Outcome." <<endl;
	cout << "3. Sort Matches By Squad Name. " <<endl;
	cout << "0. Exit to Main Menu." << endl;
	cout << endl;
	cout << "Please Make A Selection: ";
}
void setPlayerExpertise() 
{
	cout << "What is the Player's EXPERTISE?"<< endl;
	cout << endl;
	cout << "1. Tank" << endl;
	cout << "2. ADC" <<endl;
	cout << "3. Jungler" <<endl;
	cout << "4. Offlane" << endl;
	cout << "4. Support" << endl;
	cout << endl;
	cout << "Please Make a Selection: ";
}
void setStaffExpertise() 
{
	cout << "What is the staff member's EXPERTISE?"<< endl;
	cout << endl;
	cout << "1. Coach" << endl;
	cout << "2. Analyst" <<endl;
	cout << endl;
	cout << "Please Make a Selection: ";
}
void inputFriendlySquad() {cout << "Please Input friendly squad (Australis): ";}
void inputOpponent() {cout << "Please Input Opponent: ";}
void incorrectInput() {cout << "Error, Does Not Exist. Try Again? (Y/N): ";}
void inputSelection() {cout << "Please Make A Selection: ";}
void matchMenu()
{
	cout << endl;
	cout << "1. Change Player" << endl;        // 1. change player.
	cout << "2. Change Coach" << endl;         // 2. change Head Coach.
	cout << "3. Change Analyst" << endl;       // 3. change Analyst.
	cout << "4. Change SquadName" << endl;     // 4. change Squad Name.
	cout << "5. Keep Match (Manu Menu)"<< endl;// 5. Keep Squad (Main Menu)
	cout << "6. Disgard Match" << endl;        // 6. disgard Squad (Main Menu)	
	cout << endl;
	inputSelection();
	
}
void playerSwapMenu()
{
	cout << endl;
	
	cout << "1. Tank" << endl;
	cout << "2. ADC" << endl;
	cout << "3. Jungler" << endl;
	cout << "4. Offlane" << endl;
	cout << "5. Support" << endl;
	cout << "0. Change Nothing" << endl;
	cout << endl;
	cout << "which postion would you like to change?: ";
}
void postMatchMenu()
{
	
	cout << "1. Match Outcome (WIN/LOSS)" << endl;
	cout << "2. Rate A Player" << endl;
	cout << "0. Main Menu" << endl;
}
void setAvailability()
{
	cout << "1. Available" << endl;
	cout << "2. Unavailable" << endl;
	cout << "0. Exit" << endl;
}
};
// class to display output
class Display : public Menu 
{
public:
void banner()
{
	system("cls");
		cout << "          =========================================" << endl;
		cout << "                         eCoach.io" << endl;
		cout << "           A team management application for eSports" << endl;
		cout << "	         Copyright WillowSaysWhat 2023." << endl;
		cout << "          =========================================" << endl;	
		cout << endl
			 << endl;
}
void displayMatch(vector<Match> &match, size_t thisMatch)
{
	system("cls");
	cout << endl;
	cout << "=================MATCH DATA==================" << endl 
		 << endl;
	cout << "\t"<< left << setw(11) << match[thisMatch].getSquadName() << left << setw(10) <<"VERSES"<< left << setw(10) << match[thisMatch].getOpponent() << endl 
		 << endl;
	cout << "----------------------------------------------" << endl 
		 << endl;
	cout << "\tSTAFF" << endl;
	cout << left<< setw(10) << "Coach: " << match[thisMatch].getHeadCoach()<< endl;
	cout << left<< setw(10) << "Analyst: " << match[thisMatch].getAnalyst() <<endl;
	cout << endl;
	cout << "\tPLAYERS" << endl; 
	cout << left << setw(9) << "Tank: " << left << setw(15) << match[thisMatch].getTank() << left << setw(10) << "ADC: " << match[thisMatch].getADC() << endl; 
	cout << left << setw(5) << "Jungler: " << left << setw(15) << match[thisMatch].getJungler() << left << setw(10) << "Offlane: " << match[thisMatch].getOfflane() << endl; 
	cout << "Offlane: " << match[thisMatch].getSupport() << endl; 
	cout << endl;	 
	cout <<fixed << setprecision(1) << "Squad Rating: " << left << setw(10) << match[thisMatch].getSquadRating() << "Outcome: " << match[thisMatch].getOutcome() << endl;
	cout << endl;

	
}
void displayMatchTable(vector<Match> matches)
{
	cout << "\t|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout <<  left << setw(17)<< "\t|Friendly"  << left << setw(17) << "|Opponent" << left << setw(17) << "|Coach" << left << setw(17) << "|Analyst" << left << setw(17) << "|Tank" << left << setw(17) << "|ADC" << left << setw(17) << "|Jungler" <<left<< setw(17) << "|Offlane" << left << setw(17) << "|Support" << left << setw(10) << "|Rating" << left << setw(10) << "|Outcome  |";
    cout << endl;
	for (auto &m: matches)
	{
		cout << fixed << setprecision(1) << left << setw(17) << "\t|" + m.getSquadName() << left << setw(17) << "|" + m.getOpponent() << left << setw(17) << "|" + m.getHeadCoach()  << left << setw(17) << "|" + m.getAnalyst() << left << setw(17) << "|" + m.getTank() << left << setw(17) << "|" + m.getADC()  << left << setw(17)  << "|" + m.getJungler()  << left << setw(17) << "|" + m.getOfflane() << left << setw(17) << "|" + m.getSupport() << "|" << left << setw(9) <<  m.getSquadRating()  << left << setw(10)<< "|" + m.getOutcome() << "|" << endl;
	}
	cout << "\t|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
}
void displayPlayerTable(vector<Player>&players) // look at getting rid of squad column **************************************************
{

	int i = 0, endhere;

    cout << "\t|-----------------------------------------------------------------------------------------------------------------------|" << endl;
    cout <<  left << setw(20)<< "\t|Name"  << left << setw(15)  << "|Expertise" << left << setw(15) << "|Availability" << left << setw(15) << "|Avg Rating" << left << setw(12) << "|1st Game" <<left<< setw(11) << "|2nd Game" << left << setw(11) << "|3rd Game" << left << setw(11) << "|4th Game" << left << setw(11) << "|5th Game  |";
    cout << endl;

				 
	for (auto &p: players)
	{
		i = p.getLengthRecenRatings() - 1;
		endhere = i - 5;
		cout << fixed << setprecision(1) << left << setw(20) << "\t|" + p.getName()  << left << setw(15) << "|" + p.getExpertise() << left << setw(15) << "|" + p.getCurrentAvail() << "|" << left << setw(15)  << p.getAverageRating();
					
		for (;i > endhere; i--)
		{
			cout << fixed << setprecision(1) << "|" << left << setw(10)<< p.getRecentRating(i);
		}
		cout << left << setw(20)<< "|";
		cout << endl;
	}
	cout << "\t|-----------------------------------------------------------------------------------------------------------------------|" << endl;			
}
void displaySupportStaff(vector<Support> supportStaff)
{
	{
	
            	cout << "\t|---------------------------------------------------------------------------------------------|" << endl;
            	cout <<  left << setw(20)<< "\t|Name"  << left << setw(30) << "|Email" << left << setw(15) << "|Phone" << left << setw(15) << "|Expertise" << left << setw(15) << "|Availability" << "|";
            	cout << endl;

				 
				for (auto &p: supportStaff)
				{
					cout << fixed << setprecision(1) << left << setw(20) << "\t|" + p.getName() << left << setw(30) << "|" + p.getEmail() <<left << setw(15) << "|" + p.getPhone()<< left << setw(15) << "|" + p.getExpertise() << left << setw(15) << "|" + p.getCurrentAvail();
					cout << left << setw(20)<< "|";
					cout << endl;
				}
				cout << "\t|---------------------------------------------------------------------------------------------|" << endl;
}
}		
void displayBuildingTeam()
{
	cout << endl 
		 << "Building team now!" << endl
		 << endl;
		 system("pause"); // find out how to make 3 second wait ******************************************
}
void squadIsReady()
{
	cout << endl;
	cout << "Your squad is ready! please return after the Game to add results to the 'Post Game' menu." << endl;
	cout << endl;
}
void changeOpponent() {cout << "Change Opponent Name? (Y/N): ";}
void pleaseInputFriendly() {cout << "Please Input Friendly Squad Name: ";}
void pleaseInputOpponent() {cout << "Please Input Opponent: ";}
void squadDiscarded() {cout << "Squad has been discarded... Returning to main";}
void inputNewCoach() {cout << "Please input COACH: ";}
void inputNewPLayer() {cout << "please input PLAYER: ";}
void inputNewAnalyst() {cout << "Please input new ANALYST: ";}
void inputNewStaff() {cout << "Please input new STAFF: ";}
void inputNewRating() {cout << "Please input Rating: ";}
void analystSet() {cout << "Analyst changed!";}
void coachSet() {cout << "Coach changed!";}
void opponentset() {cout << "\nOpponent Set!" << endl << endl;}
void winOrLoss() 
{
	cout << "1. WIN" << endl;
	cout << "2. LOSS" << endl; 
	cout << "Make a selection: ";
}
void playerIsSet() {cout << "Player Rating is set for next match!" << endl;}
void pressEnter() {cout << "Press ENTER for exit options" << endl;}
};
//class that holds logic that is used multiple times
class Logic
{
public:
// finds highest player for the function below (newMatch)
void findHighestPlayer(vector<Player> &players, string positionName, string &player, float &rating) 
{
	bool noPlayers = true;
	
	
	for (auto &p : players) // find highest ranked Tank player in vector

	{
			// looks for the highest average rating and stores the name of that player - looks at expertise, rating, and availability
		if ((p.getExpertise() == positionName) && (p.getAverageRating() > rating) && (p.getCurrentAvail() == "Available")) 
				
			{rating = p.getAverageRating(); player = p.getName(); noPlayers = false; break; } // sets player name in fuct newMatch
	}
	if(noPlayers) {cout << "\nThere are NO PLAYERS AVAILABLE to play in that position!!" << endl;} 		
	
}
void findACoachAnalyst(vector<Support> &squadSupport, string positionName, string &name)
{
	bool noStaff = true;
	for (auto &s : squadSupport)
	{
		if((s.getExpertise() == positionName) && (s.getCurrentAvail() == "Available")) {name = s.getName(); noStaff = false; break;}
	}
	if(noStaff) {cout << "\nThere are NO STAFF AVAILABLE to play in that position!!" << endl;} 	
}

void FindPlayer(vector<Player> &players, size_t &index, string &name) 
{
	for (index = 0; index < players.size() - 1; index++)
	{	// finds index only (is passed by reference) 
		if(players[index].getName() == name) 
		{
			break;// breaks when it finds the correct name - thisPlayer in postGame() takes value
		}
		else {name = "None";}

	}
	
} // finsh this
void sortByExpertise(vector<Player> &players)
{
	for (size_t i = 0; i < players.size() - 1; i++)
	{
		for (size_t j = 0; j < (players.size() - i - 1); j++)
		{
			if (players[j].getExpertise() > players[j+1].getExpertise()) {swap(players[j], players[j+1]);}
		}
					
	}
}
void sortBySquad(vector<Match> matches)
{
	for (size_t i = 0; i < matches.size() - 1; i++)
	{
		for (size_t j = 0; j < (matches.size() - i - 1); j++)
		{
			if(matches[j].getSquadName() < matches[j+1].getSquadName()) {swap(matches[j], matches[j+1]);}
		}
					
	}
}
void sortByAverageRating(vector<Player> &players)
{
	for (size_t i = 0; i < players.size() - 1; i++)
	{
		for (size_t j = 0; j < (players.size() - i - 1); j++)
		{
			if(players[j].getAverageRating() < players[j+1].getAverageRating()) {swap(players[j], players[j+1]);}
		}
					
	}
}
void sortByOutcome(vector<Match> &matches)
{
	for (size_t i = 0; i < matches.size() - 1; i++)
	{
		for (size_t j = 0; j < (matches.size() - i - 1); j++)
		{
			if(matches[j].getOutcome() < matches[j+1].getOutcome()) {swap(matches[j], matches[j+1]);}
		}
					
	}
}
void sortBySquadRating(vector<Match> &matches)
{
	for (size_t i = 0; i < matches.size() - 1; i++)
	{
		for (size_t j = 0; j < (matches.size() - i - 1); j++)
		{
			if(matches[j].getSquadRating() < matches[j+1].getSquadRating()) {swap(matches[j], matches[j+1]);}

		}
					
	}
} 
void sortAnalystByExpertise(vector<Support> &support)
{
	for (size_t i = 0; i < support.size() - 1; i++)
	{
		for (size_t j = 0; j < (support.size() - i - 1); j++)
		{
			if(support[j].getExpertise() < support[j+1].getExpertise()) {swap(support[j], support[j+1]);}

		}
					
	}
}
void replacePlayer(vector<Player> &players, string &temp, string &originalMember, float &OmemberRating, string &expertise, bool &endLoop)
{

	for (auto &p : players)
	{
		if((p.getName() == temp) && (p.getExpertise() == expertise))
		{
			originalMember = p.getName();
			OmemberRating = p.getAverageRating();
			endLoop = true;
			break;
			
		}
		
	}
	if (endLoop == false)
	{
		cout << "This player is either not suited for this position, or does not exist... Returning to Menu." << endl;
		system("pause");
	}
	
}
void replaceCoachAnalyst(vector<Support> &support, string &temp, string &originalMember, string &expertise, bool &endLoop)
{
	for (auto &s : support)
	{
		if((s.getName() == temp) && (s.getExpertise() == expertise))
		{
			originalMember = s.getName();
			
			endLoop = true;
			continue;
			
		}
		
	}
	if (endLoop == false)
	{
		cout << "This Support Staff Member is either not suited for this position, or does not exist... Returning to Menu." << endl;
		system("pause");
	}
	
}
void setAvailability(vector<Player> &player, size_t &index, size_t &UserInput)
{
	string a = "Available", u = "Unavailable";
	// changes the availability in each player
	if(UserInput == 1) {player[index].setCurrentAvail(a); cout << "Availability changed!" <<endl;}
	else if (UserInput == 2) {player[index].setCurrentAvail(u); cout << "Availability changed!" <<endl;}
}
void savePlayers(vector<Player> &players)
{
	ofstream fileOutput;
	

	fileOutput.open("players.csv");

	if(fileOutput.is_open())
	{
		
		for (auto &p : players)
		{
			
			fileOutput << fixed << setprecision(1) << p.saveFirstNameToFile() << ',' << p.saveSecNameToFile() << ',' << p.getCurrentAvail() << ',' << p.getExpertise() << ',' << p.getRecentRating(4) << ',' << p.getAverageRating() 
			<< ',' << p.getRecentRating(4) << ',' << p.getRecentRating(3) << ',' << p.getRecentRating(2) << ',' << p.getRecentRating(1) << ',' << p.getRecentRating(0) << endl;
		}
		
	}


}
void saveStaff(vector<Support> &support)
{
	ofstream fileOutput;
	

	fileOutput.open("Coaches.csv");

	if (fileOutput.is_open())
	{
		for(auto &s : support)
		{
			fileOutput << s.saveFirstNameToFile() << ',' << s.saveSecNameToFile() << ',' << s.getCurrentAvail() << ',' << s.getExpertise() << ',' << s.getPhone() << endl;
		}
	}
}
void saveMatches(vector<Match> &matches)
{
	ofstream fileOutput;

	fileOutput.open("Matches.csv");

	if (fileOutput.is_open())
	{
		for (auto &m : matches)
		{
			fileOutput << m.getSquadName() << ',' << m.getOpponent() << ','<< m.getHeadCoach() << ',' << m.getAnalyst() << ',' << m.getTank() <<','<< m.getADC() << ',' << m.getJungler() <<',' << m.getOfflane() << ','
			<< m.getSupport() << '\n'; 
		}
		 
		//(team, opponent, coach, analyst, tank, ADC, jungler, offlane, support)
	}
}
};


// static functions 
	
void makeNewPlayersAndStaff(vector<Player> &players, vector<Support> &squadSupport, Display &display, Logic logic)
{
	//Player playertemp(fname, sname, available, stof(rating1), stof(rating2), stof(rating3),stof(rating4), stof(rating5), expertise)
	//Support supporttemp(fname, sname, available, phone, expertise);
	string fname, sname, availability, expertise, phone;
	float rating1 = 0, rating2 = 0, rating3 = 0, rating4 = 0, rating5 = 0;
	size_t UserInput;
	bool endMenu = false;
	
	
	do
	{
		system("cls");
		display.banner();
		display.NewPlayerAndStaffMenu();
		cin >> UserInput;
		switch (UserInput)
		{
		case 1:	
		{		
			system("cls");
			display.banner();
			display.inputNewPLayer();
			cout << "(First Name): ";
			cin >> fname;
			cout << endl;
			display.inputNewPLayer();
			cout << "(second Name): ";
			cin >> sname;
				
			do
			{
				system("cls");
				display.banner();
				cout << endl;
				cout << "Select 1 or 2" << endl;
				cout << endl;
				display.setAvailability();
				cin >> UserInput;
				
				switch (UserInput)
				{
				case 1:
						availability = "Available";
					endMenu = true;
					break;
				case 2:
					availability = "Unavailable";
					endMenu = true;
					break;
				default:
					break;
				}
					
			} while (!endMenu); 
				
				endMenu = false;

			do
			{
				system("cls");
				display.banner();
				display.setPlayerExpertise();
				cin >> UserInput;
				switch (UserInput)
				{
				case 1:
					expertise = "Tank";
					endMenu = true;
					break;
				case 2:
					expertise = "ADC";
					endMenu = true;
					break;
				case 3:
					expertise = "Jungler";
					endMenu = true;
					break;
				case 4:
					expertise = "Offlane";
					endMenu = true;
					break;
				case 5:
					expertise = "Support";
					break;
					
				default:
					break;
				}
								
			} while (!endMenu);
				
				
			//build player
			Player p(fname, sname, availability, rating1, rating2, rating3, rating4, rating5, expertise);
			players.push_back(p);
			cout << endl;
			cout << "Player Created!" << endl;
			cout << endl;
			system("pause");

			logic.savePlayers(players);	
			break;
		}
		case 2:
		{
			system("cls");
			display.banner();
			display.inputNewStaff();
			cout << "(First Name): ";
			cin >> fname;
			cout << endl;
			display.inputNewStaff();
			cout << "(second Name): ";
			cin >> sname;

				do
			{
				system("cls");
				display.banner();
				cout << endl;
				cout << "Select 1 or 2" << endl;
				cout << endl;
				display.setAvailability();
				cin >> UserInput;
				
				switch (UserInput)
				{
				case 1:
						availability = "Available";
					endMenu = true;
					break;
				case 2:
					availability = "Unavailable";
					endMenu = true;
					break;
				default:
					break;
				}
					
			} while (!endMenu); 


			do
			{
				system("cls");
				display.banner();
				display.setStaffExpertise();
				cin >> UserInput;
				switch (UserInput)
				{
				case 1:
					expertise = "Coach";
					endMenu = true;
					break;
				case 2:
					expertise = "Analyst";
					endMenu = true;
					break;					
				default:
					break;
				}
								
			} while (!endMenu);

			system("cls");
			display.banner();
			cout << endl;
			cout << "Enter STAFF phone number: ";
			cin >> phone;

			Support s(fname, sname, availability, phone, expertise);

			squadSupport.push_back(s);

			break;
		}
		default:
			break;
		}
		
	} while (UserInput != 0);
}


void newMatch(Logic &logic, Display display, vector<Player> &players, vector<Support> &squadSupport,vector<Match> &matches)
{
	int UserInputMatchMenu = 0;
	char changeOpponent;
	string squadName, headCoach, analyst, tank, ADC, jungler, offlane, support, opponent, tempPlayer, expertise, oldPlayer;
	float  tankRating = 0, ADCRating = 0, junglerRating = 0, offlaneRating = 0, supportRating = 0, average = 0;
	size_t thisMatch; // holds the index for the current match 
	bool endLoop; // switch for loops in change player (case 1) 

	
		display.banner();
		display.pleaseInputFriendly();
		cin >> squadName;
		display.pleaseInputOpponent();
		cin >> opponent;
		display.displayBuildingTeam();

		// finds highest player for each place so that the auto populated team is made up of the highest rated players for each position.
		logic.findHighestPlayer(players, "Tank", tank,tankRating);
		logic.findHighestPlayer(players, "ADC", ADC,ADCRating);
		logic.findHighestPlayer(players,"Jungler", jungler,junglerRating);
		logic.findHighestPlayer(players, "Offlane", offlane,offlaneRating);
		logic.findHighestPlayer(players, "Support", support, supportRating);
		logic.findACoachAnalyst(squadSupport, "Coach", headCoach);
		logic.findACoachAnalyst(squadSupport, "Analyst", analyst);
		
		// puts data into vector
		Match temp (squadName, opponent,headCoach,analyst, tank, ADC, jungler, offlane, support);
		average = tankRating + ADCRating + junglerRating + offlaneRating + supportRating;
		average = average / 5;
		temp.setSquadRating(average); // sets the overall rating of the squad
		matches.push_back(temp);

		// finds the new squad, then stops the loop so the index number is in var thisMatch.
		for (thisMatch = 0; thisMatch < matches.size(); thisMatch++) {if(matches[thisMatch].getSquadName() == squadName) {break;}} 

		//passes the index into a display method in class Display so the correct match is displayed.
	do // menu loop
	{
				
		display.displayMatch(matches,thisMatch);
		display.matchMenu();
		cin >> UserInputMatchMenu;
		
		endLoop = false;

		switch (UserInputMatchMenu)
		{
		case 1:
			// change player
			do//menu loop
			{
				logic.sortByExpertise(players);// sort vector so expertise is in alphabetical order
				system("cls");
				display.displayMatch(matches,thisMatch);
				display.playerSwapMenu();
				cin >> UserInputMatchMenu;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				switch (UserInputMatchMenu)
				{
				case 1:
					//tank
					system("cls");
					display.displayMatch(matches,thisMatch);
					display.displayPlayerTable(players); 

					expertise = "Tank";

					cout << endl;
					display.inputNewPLayer();

					getline(cin,tempPlayer);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					logic.replacePlayer(players,tempPlayer,tank, tankRating, expertise, endLoop);
					matches[thisMatch].setTank(tank);	
					
					
					break;
				case 2:
					//ADC
					system("cls");
					display.displayMatch(matches,thisMatch);
					display.displayPlayerTable(players); 
					expertise = "ADC";

					cout << endl;
					display.inputNewPLayer();
				
					getline(cin,tempPlayer);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	
					logic.replacePlayer(players,tempPlayer,tank, tankRating, expertise, endLoop);
					matches[thisMatch].setTank(tank);	
					
					break;
				case 3:
					//Jungler
					system("cls");
					display.displayMatch(matches,thisMatch);
					display.displayPlayerTable(players); 
					expertise = "Jungler";

					cout << endl;
					display.inputNewPLayer();
				
					getline(cin,tempPlayer);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	
					logic.replacePlayer(players,tempPlayer,tank, tankRating, expertise, endLoop);
					matches[thisMatch].setTank(tank);	
					break;
					
				case 4:
					//Offlane
					system("cls");
					display.displayMatch(matches,thisMatch);
					display.displayPlayerTable(players); 
					expertise = "Jungler";

					cout << endl;
					display.inputNewPLayer();
				
					getline(cin,tempPlayer);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	
					logic.replacePlayer(players,tempPlayer,tank, tankRating, expertise, endLoop);
					matches[thisMatch].setTank(tank);	
					break;
					
				case 5:
					//support
					system("cls");
					display.displayMatch(matches,thisMatch);
					display.displayPlayerTable(players); 
					expertise = "Support";

					cout << endl;
					display.inputNewPLayer();
				
					getline(cin,tempPlayer);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	
					logic.replacePlayer(players,tempPlayer,tank, tankRating, expertise, endLoop);
					matches[thisMatch].setTank(tank);	
					break;
				
				default:
					break;
				}
				average = tankRating + ADCRating + junglerRating + offlaneRating + supportRating;
				average = average / 5;
				matches[thisMatch].setSquadRating(average); // resets the squad average in matches now that new players have been added.
				{
				
	}
			} while (UserInputMatchMenu != 0);
			
			break;

		case 2:
			// change coach
			expertise = "Coach";
			system("cls");
			display.displayMatch(matches,thisMatch);
			display.displaySupportStaff(squadSupport);
			display.inputNewCoach();

			getline(cin,tempPlayer);
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			logic.replaceCoachAnalyst(squadSupport, tempPlayer, headCoach, expertise, endLoop);

			matches[thisMatch].setCoach(headCoach);// sets coach in vector
			cout << endl;
			
			break;

		case 3:
			//change analyst
			expertise = "Analyst";
			system("cls");
			display.displayMatch(matches,thisMatch);
			display.displaySupportStaff(squadSupport);
			display.inputNewAnalyst();

			getline(cin,tempPlayer);
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			logic.replaceCoachAnalyst(squadSupport, tempPlayer, analyst, expertise, endLoop);

			matches[thisMatch].setAnalyst(analyst); // sets analyst in vector
			cout << endl;
			break;
			
			

		case 4:
			//change squad name
			display.inputFriendlySquad();

			getline(cin,tempPlayer);
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			matches[thisMatch].setSquadName(squadName); // sets squad name in vector

			display.changeOpponent();
			cin >> changeOpponent;
			if (toupper(changeOpponent) =='Y')
			{
				display.inputOpponent();
				cin >> opponent;
				matches[thisMatch].setOpponent(opponent);// sets opponent in vector
				display.opponentset();
			}

			break;
		case 5:
			// keep squad
			display.squadIsReady();
			UserInputMatchMenu = 6;
			break;
		case 6:
			// discard squad
			display.squadDiscarded();
			matches.pop_back();
			break;

		default:
			break;
		}
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	// saves changes to file
	logic.saveMatches(matches);
	} while (UserInputMatchMenu != 6);
	
}

void postMatch(vector<Player> &players,vector<Match> &matches, Display &display, Logic &logic) // you need to implement error catches on the player and match inputs.
{
	int UserInput, winOrLoss;
	float newRating;
	string friendly, opponent, outcome, playersName;
	size_t thisMatch = 0, thisPlayer; // indexes found in for loops
	bool exitMenu = false;
	do
	{
		display.banner();
		display.postMatchMenu();
		display.inputSelection();
		cin >> UserInput;
		cin.clear();
		cin.ignore(100,'\n');

		switch (UserInput)
		{
		case 1:
			// update match WIN/LOSS
			display.banner();
			display.inputFriendlySquad();

			getline(cin,friendly);
			cin.clear();

			display.inputOpponent();
			getline(cin, opponent);
			cin.clear();
			
			//finds the index for the match by searching through vector<Matches> 
			for(thisMatch = 0; thisMatch < matches.size(); thisMatch++) {if((matches[thisMatch].getSquadName() == friendly) && (matches[thisMatch].getOpponent() == opponent)){break;}}

			do
			{
				// adding WIN or LOSS to match screen
				display.displayMatch(matches, thisMatch);
				cout << endl;
				display.winOrLoss();
				cin >> winOrLoss;
				cin.clear();
				
				
				switch (winOrLoss)
				{
				case 1:
				
					outcome = "WIN";
					matches[thisMatch].setOutcome(outcome);
					exitMenu = true;

					display.displayMatch(matches, thisMatch);
					system("pause");
					break;
				case 2:
					outcome = "LOSS";
					matches[thisMatch].setOutcome(outcome);
					exitMenu = true;

					display.displayMatch(matches, thisMatch);
					system("pause");
					break;
				default:
					break;
				}
			} while (exitMenu == false);
			
			//save outcome to file
			logic.saveMatches(matches);

			break;
		case 2: 
			// Player Rating
			display.banner();	
			
			display.displayPlayerTable(players);
			cout << endl;
			// find player
			display.inputNewPLayer();
			cin.clear();
			getline(cin,playersName);
			
			
			 // finds player in vector<Player>
			for(thisPlayer = 0; thisPlayer < players.size(); thisPlayer++) {if(players[thisPlayer].getName() == playersName){break;}}
			

			cout << "You entered " << players[thisPlayer].getName() << endl;

			display.inputNewRating();

			cin >> newRating;
			

			players[thisPlayer].setRecentRatings(newRating);

			cout << "player Recent Rating set" << endl;

			players[thisPlayer].setAverageRating();
			cout << "Player rating" << players[thisPlayer].getAverageRating() << endl;			
			
			display.displayPlayerTable(players);
			cout << endl;
			display.playerIsSet();
			system("pause");
			
			//save updated data to file
			logic.savePlayers(players);

			break;
		
		default:
			break;
		}
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (UserInput != 0);
	
}

void Availability(vector<Player> players, Display display, Logic logic)
{
	string name;
	size_t thisPlayer = 0, UserInput;
	bool exitMenu = false;
	do // error handling for finding player
	{

		display.banner();
		display.displayPlayerTable(players);
		cout << endl;
		display.pressEnter();
		display.inputNewPLayer();
		getline(cin,name);
		cin.ignore(100,'\n');
		cout << endl;
		
	
		logic.FindPlayer(players, thisPlayer, name);
		
		
		display.setAvailability();
		display.inputSelection();
		cin >> UserInput;
		logic.setAvailability(players, thisPlayer, UserInput);
		if(UserInput == 0) {break;} //returns to main menu

	} while (!exitMenu);
	
}

void displayPlayerData(vector<Player> &players, Logic &logic, Display &display)
{
	int UserInput;
	do
	{
		display.banner();
		display.PlayerStatsMenu();
		cin >> UserInput;

		if (!cin.fail())
		{
			switch (UserInput)
			{

			case 1:
				//rating
				logic.sortByAverageRating(players);
				system("cls");
				display.banner();
				cout << "\t\t\t\t\t\t\t\t\tPLAYER DATA BY RATING"<< endl;
				display.displayPlayerTable(players);
				cout << endl;
				system("pause");
				break;
			case 2:
				
				logic.sortByExpertise(players);
				system("cls");
				display.banner();
				cout << "\t\t\t\t\t\t\t\t\tPLAYER DATA BY EXPERTISE"<< endl;
				display.displayPlayerTable(players);
				cout << endl;
				system("pause");
				break;
			
			default:
				break;
			}

		}
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	


		
	} while (UserInput != 0);
}

void DisplayMatchData(vector<Match> &matches, Display &display, Logic &logic ) 
{
	size_t UserInput;
	
	do
	{

		system("cls");
		display.banner();
		display.matchStatsMenu();
		cin >> UserInput;
		
		switch (UserInput)
		{
		case 1:
			logic.sortBySquadRating(matches);
			display.displayMatchTable(matches);
			cout << endl;
			system("pause");
			break;
		case 2:
			logic.sortByOutcome(matches);
			display.displayMatchTable(matches);
			cout << endl;
			system("pause");
			break;
		case 3:
			logic.sortBySquad(matches);
			display.displayMatchTable(matches);
			cout << endl;
			system("pause");
			break;
	
		default:
			break;
		}
	} while (UserInput != 0);
	

}


void loadMembers(vector<Player> &players, vector<Support> &teamSupport, vector<Match> &matches) 
	{
		string playerCSV = "players.csv", coachCSV = "Coaches.csv", matchesCSV = "Matches.csv",
				// variables for Players and SupportStaff
			   fname, sname, position, available, expertise, 
		   	   team, currentRating, averageRating, rating1,
		       rating2, rating3, rating4, rating5, phone, // strings for each input
				// Variables for Matches
			   opponent, coach, analyst, tank, ADC, jungler, offlane, support, outcome, squadAvgRatingStr; 
		
		
		ifstream fileInput;

		// load player data
		fileInput.open(playerCSV);
		if(fileInput.is_open())
		{
			
			
			
			
			while (fileInput) // pulls data from file using CSV
    	    {
    	        
				getline(fileInput, fname, ',');	getline(fileInput, sname, ','); getline(fileInput, available, ','); getline(fileInput, expertise, ','); getline(fileInput, currentRating, ','); getline(fileInput, averageRating, ',');
        	    getline(fileInput, rating1, ','); getline(fileInput, rating2, ','); getline(fileInput, rating3, ',');getline(fileInput, rating4, ','); getline(fileInput, rating5, '\n');

            	if(fileInput.eof()) break;

				Player playertemp(fname, sname, available, stof(rating1), stof(rating2), stof(rating3),stof(rating4), stof(rating5), expertise);
				players.push_back(playertemp);
				
                
			}
			fileInput.ignore(1000, '\n');// ignores the blank line in the file
			
		}
		else
		{
			cout << "The player database does not exist" << endl
			<< endl;

			system("pause");
		}
		fileInput.close();
		
		// load coach and analyst data
		fileInput.open(coachCSV);
		
		if(fileInput.is_open())
		{
			while (fileInput)
			{
				getline(fileInput, fname, ',');
				getline(fileInput, sname, ',');
        	    getline(fileInput, available, ',');
        	    getline(fileInput, expertise, ',');
				getline(fileInput, phone, '\n');  

				

				Support supporttemp(fname, sname, available, phone, expertise);
				teamSupport.push_back(supporttemp);
				
				if(fileInput.eof()) break;
				
			}
			fileInput.ignore(1000, '\n');// ignores the blank line in the file			
		}
		else
		{
			cout << "The support database does not exist" << endl
				 << endl;

			system("pause");
		}
		fileInput.close();

		fileInput.open(matchesCSV);
		
		if (fileInput.is_open())
		{
			while (fileInput)
			{
				cout << "loading match" << endl;
				getline(fileInput, team, ',');
				getline(fileInput, opponent, ',');
				getline(fileInput, coach, ',');
        	    getline(fileInput, analyst, ',');
        	    getline(fileInput, tank, ',');
        	    getline(fileInput, ADC, ',');
				getline(fileInput, jungler, ',');
				getline(fileInput, offlane, ',');
				getline(fileInput, support, ',');
				getline(fileInput, outcome, ',');
				getline(fileInput, squadAvgRatingStr, '\n');
				
				
				Match matchtemp (team, opponent, coach, analyst, tank, ADC, jungler, offlane, support);
				matchtemp.setSquadRating(stof(squadAvgRatingStr));
				matchtemp.setOutcome(outcome);
				matches.push_back(matchtemp);
				
				if(fileInput.eof()) break;
				
			}
			fileInput.ignore(1000, '\n');// ignores the blank line in the file			
		}
		else
		{
			cout << "The Match database does not exist" << endl
			<< endl;

			system("pause");
		}
		fileInput.close();
		

	}



int main()
{
	
	Display display;
	Logic logic;
	
	vector<Player> Players;
	vector<Support> teamSupport;
	vector<Match> matches;
	loadMembers(Players, teamSupport, matches);

int UserInput;	
do
{
	display.banner();
	display.mainMenu();
	cin >> UserInput;
	if (!cin.fail())
	{
		switch (UserInput)
		{
		case 1:
			/* make a new match */
			makeNewPlayersAndStaff(Players, teamSupport, display, logic);
		
			break;
		case 2:

			newMatch(logic, display, Players, teamSupport, matches);
			break;

		case 3:
			// after match options like setting player performance, win or loss
			postMatch(Players, matches, display, logic);
			break;
		case 4:
			// availability
			Availability(Players, display, logic);
			break;

		case 5:

			displayPlayerData(Players,logic,display); 
			break;
	
		case 6: 

			logic.sortAnalystByExpertise(teamSupport);
			display.banner();
			display.displaySupportStaff(teamSupport);
			system("pause");
			break;

		case 7:	
			DisplayMatchData(matches,display,logic);
			
			break;
		default:
			break;
		}

	}
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	

} while (UserInput != 0);
	



} 
// error handling and catches

// format menus eg. player table, support table - not important

