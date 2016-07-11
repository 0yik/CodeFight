/*Consider a city where the streets are perfectly laid out to form an infinite square grid. In this city finding the shortest path between two given points (an origin and a destination) is much easier than in other more complex cities. As a new Uber developer, you are tasked to create an algorithm that does this calculation.

Given user's departure and destination coordinates, each of them located on some street, find the length of the shortest route between them assuming that cars can only move along the streets.

Example

For departure = [0.4, 1] and destination = [0.9, 3] the answer should be 2.7.



[input] array.float departure

An array [x, y] of x and y coordinates. It is guaranteed that at least one coordinate is integer.
[input] array.float destination

The destination is given the same way as the departure location.
[output] float

The shorted distance between two points along the streets.
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double perfectCity(std::vector<double> departure, std::vector<double> destination)
{

    double total = 0, x1, y1;

    if (departure[0] <= destination[0])
    {
        x1 = ceil(departure[0]);
        total += fabs(x1 - departure[0]);
        total += fabs(x1 - destination[0]);
    }
    else
    {
        x1 = floor(departure[0]);
        total += fabs(departure[0] - x1);
        total += fabs(x1 - destination[0]);
    }

    if (departure[1] <= destination[1])
    {
        y1 = floor(departure[1]);
        total += fabs(departure[1] - y1);
        total += fabs(y1 - destination[1]);
    }
    else
    {
        y1 = ceil(departure[1]);
        total += fabs(y1 - departure[1]);
        total += fabs(y1 - destination[1]);
    }

    return total;

}


int main()
{
    std::vector<double> from = {0.4,1};
    std::vector<double> to = {0.9, 3};

    cout << perfectCity(from,to) << endl;
    return 0;
}
