// brand of paint covers 340 square feet per tin. How many tins for a fence that is 6ft high by 100 feet long.
//  area is a^2*b^2

#include <iostream> //libraries.
#include <cmath>
using namespace std; // use standard namespace.

int main() // initialise function.
{
    float paintCovers = 340; // amount a can of paint covers in feet.
    int height = 6;          // height of fence.
    int length = 100;        // length of fence.

    int fenceArea = length * height; // getting the area of the fence.

    paintCovers = fenceArea / paintCovers; // find how many cans of pain by dividing area by how much one paint can will cover.

    cout << "For your fence which is " << fenceArea << "sqft"
         << " you will need " << round(paintCovers) << " tins of paint"; // displaying the output
}
