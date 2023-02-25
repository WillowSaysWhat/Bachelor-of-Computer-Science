#include <iostream> //we import the input/output stream library.

using namespace std; // we use the standard namespace.

int main() // initialise the main function.
{
    int start, finish; // make 2 integer variables - start and finish.

    cout << "please input 2 numbers," << endl; // ask the user to enter 2 numbers.
    cout << "first number: ";
    cin >> start; // input for the first variable.
    cout << "second number: ";
    cin >> finish; // input for the first variable.

    if (start > finish) // if start is a higher number than finish.
    {
        start = start + finish;
        finish = start - finish; // swap the numbers to that start is smaller than finish.
        start = start - finish;
    }
    else // if start is smaller than finish. do nothing.
    {
    }

    for (int i = start; i < (finish + 1); i++) // loop while i is less than (finish +1)
    {
        cout << i << " ";
    }

    return 0;
}