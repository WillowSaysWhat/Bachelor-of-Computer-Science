/*Average Percentage of Marks:
A school holds three terminal examinations every year.
Write a program that asks the user to enter the percentage of marks they obtained in each terminal examination in a year,
and then displays their average percentage for the year, correct to two decimal places.
Output should look like:
Average mark is < value >%
*/

#include <iostream> // use the in/out stream library
#include <iomanip>  // use the in/out manipulation library

using namespace std;

int main()
{
    float firstMark;  // holds first mark
    float secondMark; // holds second mark
    float thirdMark;  // holds third mark

    cin >> firstMark >> secondMark >> thirdMark; // input 3 marks - simplified for Code Grader

    cout << "Average mark is " << fixed << setprecision(2)
         << (firstMark + secondMark + thirdMark) / 3 << "%"; // display as stated on line (6)

    // did not return int as Shiny told me it is not needed.
}
