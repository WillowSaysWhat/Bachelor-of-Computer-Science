#include <iostream>
#include <fstream>
#include <string>

using namespace std;




int main()
{
    string playerCSV = "players.txt", name,position,available,expertise,team,currentRating,averageRating,rating1,rating2,rating3, rating4,rating5;;
    

    fstream fileInput;

    fileInput.open(playerCSV);

    if (fileInput.is_open())
    {
        while (fileInput.good())
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
            cout << " " << name << " " << position << " " << available << " " << expertise << " " <<team << " " 
                 << currentRating << " " << averageRating<< " " << rating1 << " " << rating2 << " " << rating3 << " " << rating4
                 << " " << rating5 << endl;
                 

        }
             
        
        

    }
    else
    {
        cout << "no file";
    }



}