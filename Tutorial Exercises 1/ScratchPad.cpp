#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int input[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}}, rowsAndCols = 3;

    for (size_t i = 0; i < rowsAndCols; i++)
    {
        for (size_t j = 0; j < rowsAndCols; j++)
        {
            for (size_t k = 0; k < rowsAndCols; k++)
            {
                int temp;
                if (input[i][j] < input[i][k])
                {
                    temp = input[i][k];        // add left int here
                    input[i][k] = input[i][j]; // place right int into left position
                    input[i][j] = temp;
                }
            }
        }
    }
    for (size_t i = 0; i < rowsAndCols; i++)
    {
        for (size_t j = 0; j < rowsAndCols; j++)
        {
            cout << input[i][j] << " ";
        }
    };
}