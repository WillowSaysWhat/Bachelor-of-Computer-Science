#include <iostream>
#include <vector>
#include <fstream>
#include <limits> // cin.ignore (numeric_limits<streamsize>)
#include <iomanip>

using namespace std;


class Member
{
protected:
	string name, memberPosition, currentAvailability, team;
public:
	Member (const string _name, const string _availability, const string _team) 
	: name(_name), currentAvailability(_availability), team(_team){}

virtual void SetMemberPosition() = 0;

string getName() {return name;}
string getMemberPos() {return memberPosition;}	
string getCurrentAvail(){return currentAvailability;}
string getTeam() {return team;}
};

class Player : public Member
{
protected:
    float averageRating;
public:
    Player(const string name, const string availability, const string team)
    : Member(name, availability, team){}
    void SetMemberPosition() {this->memberPosition = "Xtreme";}
    void setAverageRating() { this->averageRating = 9.9;}
    float getAverageRating() {return averageRating;}

};








int main()
{

vector<Player*> players;

players.push_back(new Player("Jay Harbor","Available","Australis"));




}