/*
You are given an n × n chessboard, stored in a two-dimensional array. There are some white and black chess pieces on it.

A normal chess rook of the given color is placed on the cell 'square'. The square is given in the standard chess notation, e.g. "a1", "h3", "b2". The position "a1" is in the lower left corner; "b1" is the square to the right-hand side of "a1"; "a2" is the square above "a1."

Your task is to return all possible moves the rook can take, sorted by squares' letters and numbers.

Example

For

chessboard = [[1, 1, 1, 0],
              [1, -1, 1, 1],
              [1, 0, 0, 0],
              [0, 0, 0, 1]],
square = "b1",
color = 1
the output should be
PossibleRookMoves(chessboard, square, color) = ["a1", "b2", "b3", "c1"].

square = "b1" means that it is to be placed at chessboard[3][1], so the rook can move to the following squares:

"a1", since it is empty (it's impossible to move further in this direction since that's the end of the chessboard);
"b2", since it is empty;
"b3", since it is occupied by the opponent's piece (note, however, that it is not possible to move further in this direction);
"c1", since it is empty (however, the rook cannot move further since the next piece is the piece of the same color).
Sorting these positions in ascending order by letter and by number, the result therefore is ["a1", "b2", "b3", "c1"].

[input] array.array.integer chessboard

A two-dimensional array that represents a square chessboard. A value of 1 indicates that the corresponding position is occupied by a white piece; a value of 0 indicates that it is empty; a value of -1 indicates that it is occupied by a black piece. It is guaranteed that the chessboard is not greater than 8 × 8 in size.
[input] string square

The square the rook is placed on. It is guaranteed that it belongs to the chessboard and is not occupied.
[input] integer color

The color of the rook piece (1 for white, -1 for black).
[output] array.string

All possible moves the rook can make sorted as described above.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


std::vector<std::string> PossibleRookMoves(std::vector<std::vector<int>> chess, std::string sqr, int cr)
{

    int n = chess.size();
    int x = (sqr[0] - 97);
    int y = abs((sqr[1] - 49) - (n - 1));
    int l = 1;
    std::vector<std::string> hasil;
    std::string s;

    for (int i = y; i < n-1; i++)
    {
        if (chess[y+l][x] == 0)
        {
            s = (x + 'a');
            s += (abs((y + l) - (n)) + '0');
            hasil.push_back(s);
            s = "";
        }

        if (chess[y+l][x] == cr*-1)
        {
            s = (x + 'a');
            s += (abs((y + l) - (n)) + '0');
            hasil.push_back(s);
            s = "";
            i = n;
        }

        if (chess[y+l][x] == cr)
            i = n;

        l++;
    }

    l = 1;
    for (int i = y; i > 0; i--)
    {
        if (chess[y-l][x] == 0)
        {
            s = (x + 'a');
            s += (abs((y - l) - (n)) + '0');
            hasil.push_back(s);
            s = "";
        }

        if (chess[y-l][x] == cr*-1)
        {
            s = (x + 'a');
            s += (abs((y - l) - (n)) + '0');
            hasil.push_back(s);
            s = "";
            i = 0;
        }

        if (chess[y-l][x] == cr)
            i = 0;

        l++;
    }

    l = 1;
    for (int i = x; i < n-1; i++)
    {
        if (chess[y][x+l] == 0)
        {
            s = ((x+l) + 'a');
            s += (abs(y - n) + '0');
            hasil.push_back(s);
            s = "";
        }

        if (chess[y][x+l] == cr*-1)
        {
            s = ((x+l) + 'a');
            s += (abs(y - n) + '0');
            hasil.push_back(s);
            s = "";
            i = n;
        }

        if (chess[y][x+l] == cr)
            i = n;

        l++;
    }

    l = 1;
    for (int i = x; i > 0; i--)
    {
        if (chess[y][x-l] == 0)
        {
            s = ((x-l) + 'a');
            s += (abs(y - n) + '0');
            hasil.push_back(s);
            s = "";
        }

        if (chess[y][x-l] == cr*-1)
        {
            s = ((x-l) + 'a');
            s += (abs(y - n) + '0');
            hasil.push_back(s);
            s = "";
            i = 0;
        }

        if (chess[y][x-l] == cr)
            i = 0;

        l++;
    }

    std::sort(hasil.begin(),hasil.end());
    return hasil;
}


int main()
{
    std::vector<std::vector<int>> chessboard =
    {
        {0,1,0,-1,0},
        {0,0,-1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {-1,0,1,1,0}
    };
    std::vector<std::string> moveRook = PossibleRookMoves(chessboard, "c5", 1);

    for (int i = 0; i < moveRook.size(); i++)
    {
        cout << moveRook[i] << endl;
    }

    return 0;
}
