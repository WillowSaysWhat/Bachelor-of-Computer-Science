// this program changes a person's height from feet/inches to metres.
// the coversion is 1 inch is equal to 2.54cm.
#include <iostream> //use in/out stream library.
#include <iomanip>  // use this library to get precise output.

using namespace std; // use standard namespace.

int main() // initialize integer function.
{
    float feet;   // make float variable. call it feet.
    float inches; // make float variable, call it inches.

    cout << "<enter feet, then inches>";
    cout << "please enter your height: "; // display to prompt user.
    cin >> feet >> inches;                // 2 inputs. one for feet and the second for inches.

    float meters = ((((feet * 12) + inches) * 2.54) / 100);                              // converting feet to inches; adding more inches; * 2.54cm; convert to meters.
    cout << "Height in feet and inches is " << feet << "ft, " << inches << "in" << endl; // displaying user's height in feet and inches.
    cout << "Height in meters is " << fixed << setprecision(2) << meters << "m";         // displaying the conversion to meters/
    return 0;                                                                            // return integer.
}