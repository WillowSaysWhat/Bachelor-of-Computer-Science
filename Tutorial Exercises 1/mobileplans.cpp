/*
Output should look like:
Customers Bill
Plan < value >
Total cost for this month is: $< value >
You would get a better deal on plan < value > : $ < value >
*/

#include <iostream>

using namespace std;

float plans(char whichPlan, float minutes, float data) // takes in the chosen plan(eg 'A') - extra mins(eg 400) - extra data (15)
                                                       // adds up the total of each plan and returns it to main.
{                                                      //
    float total;                                       // variable to return totals
    if (whichPlan == 'A')                              // if the customer plan is 'A'
    {                                                  //
        if (minutes > 450 && data > 1)                 // if extra mins are greater than 450, and extra data is greater than 1
        {
            total = 29.99 + ((minutes - 450) * 0.45) + ((data - 1) * 2); // the cost of extra mins and data to origninal price
        }                                                                //
        else if (minutes > 450 && data <= 1)                             // if only mins are greater
        {                                                                //
            total = 29.99 + ((minutes - 450) * 0.45);                    // add cost of mins to original price
        }                                                                //
        else if (minutes <= 450 && data > 1)                             // if only data is greater
        {                                                                //
            total = 29.99 + ((data - 1) * 2);                            // add cost of data to original price
        }                                                                //
        else if (minutes <= 450 && data <= 1)                            // if both are less
        {                                                                //
            total = 29.99;                                               // just return original price
        }                                                                //
    }                                                                    //
    else if (whichPlan == 'B')                                           // do the same with 'B
    {
        if (minutes > 900 && data > 3)
        {
            total = 39.99 + ((minutes - 900) * 0.40) + ((data - 3) * 1.5);
        }
        else if (minutes <= 900 && data > 3)
        {
            total = 39.99 + ((data - 3) * 1.5);
        }
        else if (minutes > 900 && data < 3)
        {
            total = 39.99 + ((minutes - 900) * 0.4);
        }
    }

    return total; // return to main function for further use
}

void DecideNewPlan(char plan, float a, float b, float c) // takes in chosen plan('A') plan totals returned to main from the above function
{                                                        //
                                                         //
    float total, smallest;                               // var for total and a var for assisting in finding the smallest price in each if statement
    char listOfPlans[3] = {'A', 'B', 'C'}, newPlan;      // array with each character, and a var for the new plan

    if (plan == 'A') // if char in plan is 'A'
    {
        smallest = a; // a is placed into smallest.

        if (smallest > b) // compare a and b - if b is smaller
        {
            smallest = b;                       // the smallest package is b
            newPlan = listOfPlans[1];           // char 'b' is the new plan
        }                                       //
        if (smallest > c)                       // if c is smaller
        {                                       //
            smallest = c;                       // smallest is replace with c
            newPlan = listOfPlans[2];           // new plan is now c
        }                                       //
                                                //
        if (smallest == a)                      // if a is the smallest
        {                                       //
            cout << "You are on the best deal"; // a is the best deal
        }                                       //
        else                                    // otherwise
        {                                       // display new plan
            cout << "You would get a better deal on plan " << newPlan << ": $" << smallest;
        }
    }
    if (plan == 'B') // do the exaxt same for 'B'
    {
        smallest = b;
        if (smallest > a)
        {
            smallest = a;
            newPlan = listOfPlans[0];
        }
        if (smallest > c)
        {
            smallest = c;
            newPlan = listOfPlans[2];
        }
        else
        {
        }

        if (smallest == b)
        {
            cout << "You are on the best deal";
        }
        else
        {
            cout << "You would get a better deal on plan " << newPlan << ": $" << smallest;
        }
    }
    if (plan == 'C') // Do the exact same for 'C'
    {
        smallest = c;
        if (smallest > a)
        {
            smallest = a;
            newPlan = listOfPlans[0];
        }
        if (smallest > b)
        {
            smallest = b;
            newPlan = listOfPlans[1];
        }
        else
        {
        }

        if (smallest == c)
        {
            cout << "You are on the best deal";
        }
        else
        {
            cout << "You would get a better deal on plan " << newPlan << ": $" << smallest;
        }
    }
}

void displayPrice(char plan, float planA, float planB, float planC) // made a function to display the total costs
{                                                                   // I could have just printed them in main, but I decided to do this insead.
    if (plan == 'A')                                                // If char ('A', 'B', 'C') is in plan
    {                                                               //
        cout << "Total cost for this month is: $" << planA << endl; // output this.
    }

    else if (plan == 'B')
    {
        cout << "Total cost for this month is: $" << planB << endl;
    }
    else if (plan == 'C')
    {
        cout << "Total cost for this month is: $" << planC << endl;
    }
}

int main()
{

    char plan;                                     // var to hold the letter inputted by user
    float mins, data, planA, planB, planC = 59.99; // var for each plan with plan c amount already initiated
    string name;                                   // var for name input

    cin >> name >> plan >> mins >> data; // request input

    cout << "Customers Bill " << endl         // first heading
         << "Plan " << plan << endl;          // immediately display the plan
                                              //
    planA = plans('A', mins, data);           // place the return value from function plan here
    planB = plans('B', mins, data);           // place return here
                                              //
    displayPrice(plan, planA, planB, planC);  // run funstion
    DecideNewPlan(plan, planA, planB, planC); // run function
}