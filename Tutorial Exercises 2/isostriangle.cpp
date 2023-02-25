/*
Output should look like:

Area <value>
Perimeter <value>
*/
#include <iostream>
#include <cmath> // using cmath to acces the square root function
using namespace std;

class IsoscelesTriangle // create class
{
private:
    double base = 0, // create 2 variables for base and height as instraucted
        height = 0;

public:
    IsoscelesTriangle(double b, double h) // default constructor that sets base and height when object is constucted
    {
        this->base = b,
        this->height = h;
    }

    double getArea() // returns area to main
    {
        return 0.5 * (height * base);
    }

    double getPerimeter() // returns perimeter to main
    {

        return sqrt((base * base) + (4 * (height * height))) + base;
    }
};

int main()
{
    double baseInput, // variable for input of base and height
        heightInput;
    cin >> baseInput >> heightInput; // requests input

    IsoscelesTriangle firstTriangle(baseInput, heightInput); // creates object with 2 arguments

    cout << "Area " << firstTriangle.getArea() << endl // displays area and perimeter via object
         << "Perimeter " << firstTriangle.getPerimeter();
}