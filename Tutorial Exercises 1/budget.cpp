/*Output should look like:
Here is your cost breakdown
Monthly Rent: $ < value >
Yearly Rent: $< value >
Monthly Internet:$ < value >
Yearly Internet: $ < value >
Monthly Gas: $ < value >
Yearly Gas: $ < value >
Monthly Electricity: $ < value >
Yearly Electricity: $ < value >
Monthly Water: $ < value >
Yearly Water: $ < value >
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // As I do not know whether the input will include a decimal, I will use floats.
    float rentOrMortgage; // holds the monthly rent
    float internet;       // holds internet cost, monthly
    float gas;            // input for monthly gass
    float electricity;    // monthly electricity
    float water;          // water per month

    cin >> rentOrMortgage >> internet >> gas >> // input for all 5 variables - simplified with no prompt displayed
        electricity >> water;                   // as it causes a Code Grader output error.

    cout << "Here is your cost breakdown" << endl
         << fixed << setprecision(2)                        // expected heading for output
         << "Monthly Rent: $" << rentOrMortgage << endl     // displays the variable
         << "Yearly Rent: $" << rentOrMortgage * 12 << endl // displays variable times (*) by 12 months to make yearly
         << "Monthly Internet: $" << internet << endl       // see comment on line (32)
         << "Yearly Internet: $" << internet * 12 << endl   // see comment on line (33)
         << "Monthly Gas: $" << gas << endl
         << "Yearly Gas: $" << gas * 12 << endl
         << "Monthly Electricity: $" << electricity << endl
         << "Yearly Electricity: $" << electricity * 12 << endl
         << "Monthly Water: $" << water << endl
         << "Yearly Water: $" << water * 12 << endl;
}