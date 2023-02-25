
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <typeindex>
using namespace std;

int main ()
{
    ifstream file("floorscustomer.txt");
    
    string content;
    vector<string> tempdata;
    
    while (getline(file, content))
    {
        cout << content << endl;
        tempdata.push_back(content);
        
    }
    file.close();

    for (size_t i = 0; i < tempdata.size(); i++)
    {
        cout << tempdata[i] << " ";
    }
    
    // check the output
    
    
    
}