/*Bridge is a card game played with a deck of playing cards. The deck contains exactly 52 unique cards with 4 suits, each containing 13 cards which ascend in value from 2 through 10 and then to Jack, Queen, King and Ace. The suits are ranked in ascending order as Clubs, Diamonds, Hearts and Spades.

4 people are required to play a hand of bridge. Each person is dealt one card at a time until the deck has been exhausted. That means each person ends up with 13 unique cards randomly selected from the 52 available.

Your job is to sort your hand in descending order, first by suits and then by card values within the suit.

For simplicity cards are represented by 2 characters. The second character is the suit: 'S', 'H', 'D', 'C' for Spades, Hearts, Diamonds and Clubs respectively. The first character is the value with the Ace, King, Queen, Jack and 10 represented as ‘A’, ‘K’, ‘Q’, ‘J’ and ’T’ respectively, or a digit from '2' through '9'.

Example

For hand = “2C,3C,4C,5C,6C,7C,8C,9C,TC,JC,QC,KC,AC” (the entire Club suit) the output should be
SortedHand(hand) = “AC,KC,QC,JC,TC,9C,8C,7C,6C,5C,4C,3C,2C”.
For hand = "AC,KC,QC,TC,9D,8D,7D,6H,5H,4H,3S,2S,AS",
the output should be
SortedHand(hand) = "AS,3S,2S,6H,5H,4H,9D,8D,7D,AC,KC,QC,TC".
[input] string hand

13 unique cards separated by commas. Each card is represented by two characters (see the description).
[output] string

The hand sorted in descending order with cards separated by commas.
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

std::string SortedHand(std::string hand)
{

    int x;
    std::stringstream ss(hand);
    std::string spt,s;
    std::vector<std::string> tmp;
    std::vector<int> tmpi;

    while(std::getline(ss, spt, ','))
        tmp.push_back(spt);

    for(int i = 0; i < tmp.size(); i++)
    {
        spt = tmp[i];
        if (spt[1] == 'S')
        {
            if(spt[0] == 'A') tmpi.push_back(14*100019);
            else if (spt[0] == 'K') tmpi.push_back(13*100019);
            else if (spt[0] == 'Q') tmpi.push_back(12*100019);
            else if (spt[0] == 'J') tmpi.push_back(11*100019);
            else if (spt[0] == 'T') tmpi.push_back(10*100019);
            else tmpi.push_back((spt[0] - 48) * 100019);
        }
        else if (spt[1] == 'H')
        {
            if(spt[0] == 'A') tmpi.push_back(14*7127);
            else if (spt[0] == 'K') tmpi.push_back(13*7127);
            else if (spt[0] == 'Q') tmpi.push_back(12*7127);
            else if (spt[0] == 'J') tmpi.push_back(11*7127);
            else if (spt[0] == 'T') tmpi.push_back(10*7127);
            else tmpi.push_back((spt[0] - 48) * 7127);
        }
        else if (spt[1] == 'D')
        {
            if(spt[0] == 'A') tmpi.push_back(14*509);
            else if (spt[0] == 'K') tmpi.push_back(13*509);
            else if (spt[0] == 'Q') tmpi.push_back(12*509);
            else if (spt[0] == 'J') tmpi.push_back(11*509);
            else if (spt[0] == 'T') tmpi.push_back(10*509);
            else tmpi.push_back((spt[0] - 48) * 509);
        }
        else if (spt[1] == 'C')
        {
            if(spt[0] == 'A') tmpi.push_back(14*17);
            else if (spt[0] == 'K') tmpi.push_back(13*17);
            else if (spt[0] == 'Q') tmpi.push_back(12*17);
            else if (spt[0] == 'J') tmpi.push_back(11*17);
            else if (spt[0] == 'T') tmpi.push_back(10*17);
            else tmpi.push_back((spt[0] - 48) * 17);
        }
    }

    std::sort(tmpi.rbegin(), tmpi.rend());
    spt = "";
    for(int i = 0; i < tmpi.size(); i++)
    {
        if(tmpi[i] % 100019 == 0)
        {
            x = tmpi[i] / 100019;
            if (x == 14) spt += "AS,";
            else if (x == 13) spt += "KS,";
            else if (x == 12) spt += "QS,";
            else if (x == 11) spt += "JS,";
            else if (x == 10) spt += "TS,";
            else
            {
                s = x + 48;
                spt += s + "S,";
            }
        }
        else if(tmpi[i] % 7127 == 0)
        {
            x = tmpi[i] / 7127;
            if (x == 14) spt += "AH,";
            else if (x == 13) spt += "KH,";
            else if (x == 12) spt += "QH,";
            else if (x == 11) spt += "JH,";
            else if (x == 10) spt += "TH,";
            else
            {
                s = x + 48;
                spt += s + "H,";
            }
        }
        else if(tmpi[i] % 509 == 0)
        {
            x = tmpi[i] / 509;
            if (x == 14) spt += "AD,";
            else if (x == 13) spt += "KD,";
            else if (x == 12) spt += "QD,";
            else if (x == 11) spt += "JD,";
            else if (x == 10) spt += "TD,";
            else
            {
                s = x + 48;
                spt += s + "D,";
            }
        }
        else if(tmpi[i] % 17 == 0)
        {
            x = tmpi[i] / 17;
            if (x == 14) spt += "AC,";
            else if (x == 13) spt += "KC,";
            else if (x == 12) spt += "QC,";
            else if (x == 11) spt += "JC,";
            else if (x == 10) spt += "TC,";
            else
            {
                s = x + 48;
                spt += s + "C,";
            }
        }
    }

    spt.erase(spt.end()-1, spt.end());
    return spt;

}


int main()
{
    std::string card = "2C,3C,4C,5C,6C,7C,8C,9C,TC,JC,QC,KC,AC";
    cout << SortedHand(card) << endl;
    return 0;
}
