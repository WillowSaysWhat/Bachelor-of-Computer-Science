// This program works out the total monthily income including bonus and medical allowance.
// pay is 5,000.
// bonus is 55%.
// medical allowance12.5%.

#include <iostream> // include in/out stream library.

using namespace std; // use standard namespace.

int main() // initialize the main function.
{
	int pay = 5000;		   // make integer variable. name it 'pay'
	float bonus = 0.55;	   // make float variable. name it bonus.
	float medical = 0.125; // make float variable. name medical.

	cout << "Basic Pay is $" << pay << endl;							   // display basic income.
	cout << "Bonus is $" << pay * bonus << endl;						   // display $$amount of 55%.
	cout << "Medical Allowance is $" << pay * medical << endl;			   // display $$amount of 12.5%.
	cout << "Total is $" << pay + (pay * bonus) + (pay * medical) << endl; // display pay + bonus + medical.
	return 0;															   // return int.
}
