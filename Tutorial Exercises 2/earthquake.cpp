#include <iostream>
#include <vector>

using namespace std;

class Earthquake
{
private:
    double magnitude;
    string name, location;

public:
    Earthquake()
    {
        cout << "Please input Earthquake name, location, and Magnitude: ";
        cin >> name >> location >> magnitude;
    }
    string getName()
    {
        return name;
    }
    string getLocation()
    {
        return location;
    }
    double getMagnitude()
    {
        return magnitude;
    }
};

void sortArray()
{
    // return by pointers
}
void insertQuake()
{
    // add another earthquake
}
void displayData(vector<Earthquake> *vecPtr)
{

    // display sorted and unsorted
    for (size_t i = 0; i < 4; i++)
    {
        cout << "Index: " << i << " Name: " << vecPtr[i].getName // why??
    }
}

int main()
{
    Earthquake Quake1, Quake2, Quake3, Quake4;
    vector<Earthquake> objectList = {Quake1, Quake2, Quake3, Quake4};

    vector<Earthquake> *vecPtr = &objectList;

    displayData(vecPtr);
}