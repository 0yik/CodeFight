#include <iostream>
#include <vector>

using namespace std;

bool parkingSpot(std::vector<int> carDimensions, std::vector<std::vector<int>> parkingLot, std::vector<int> luckySpot)
{

    bool state = true, direction, good = false;
    int x,y;

    x = luckySpot[2]-luckySpot[0];
    y = luckySpot[3]-luckySpot[1];

    if (x < y )
        direction = true;
    else
        direction = false;

    for(int i = luckySpot[1]; i <= luckySpot[3]; i++)
    {
        if(direction)
        {
            for (int j = parkingLot[0].size()-1; j > luckySpot[3]; j--)
            {
                if (parkingLot[luckySpot[0]][j] != 0 || parkingLot[luckySpot[2]][j] != 0)
                    state = false;
                    else
                    state = true;
            }

            for (int j = 0; j < luckySpot[1]; j++)
            {
                if (parkingLot[luckySpot[0]][j] != 0 || parkingLot[luckySpot[2]][j] != 0)
                state = false;
                else
                state = true;
            }

            /*if((parkingLot[luckySpot[0]][0] != 0 || parkingLot[luckySpot[2]][0] != 0) &&
                    (parkingLot[luckySpot[0]][parkingLot[0].size()-1] != 0 || parkingLot[luckySpot[2]][parkingLot[0].size()-1] != 0))
                state = false;*/
        }
        else
        {
            for (int j = parkingLot.size()-1; j > luckySpot[2]; j--)
            {
                if (parkingLot[luckySpot[j]][i] != 0)
                    state = false;
                    else
                    state = true;
            }

            for (int j = 0; j < luckySpot[0]; j++)
            {
                if (parkingLot[luckySpot[j]][i] != 0)
                    state = false;
                    else
                    state = true;
            }

            good = false;

            /*
            if(parkingLot[0][i] != 0 && parkingLot[parkingLot.size()-1][i])
                state = false;*/
        }

        if (parkingLot[luckySpot[0]][i] != 0)
            state = false;
        if (parkingLot[luckySpot[2]][i] != 0)
            state = false;
    }

    return state;
}


int main()
{
    std::vector<std::vector<int>> parking =
    {
        {1,1,1,1,1,1,1},
        {0,0,1,1,0,0,0},
        {1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {1,0,0,0,1,1,1},
        {1,1,1,1,1,1,1}
    };
    cout << parkingSpot({3,2}, parking, {2,2,4,3}) << endl;
    return 0;
}
