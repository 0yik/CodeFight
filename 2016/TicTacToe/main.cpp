/*
You are given a 3 × 3 Tic-tac-toe board stored as a two-dimensional array. Find out the winner of the game, or return ' ' if there is no winner.

Example

For
board = [['x', 'x', 'x'],
         [' ', 'o', ' '],
         ['o', ' ', 'x']]
the output should be TicTacToe(board) = 'x', since there are three consecutive 'x's in the top row.

For
board = [['x', 'x', 'o'],
         [' ', 'o', ' '],
         ['o', ' ', 'x']]
the output should be TicTacToe(board) = 'o', since there are three consecutive 'o's on the diagonal.

For
board = [['x', ' ', ' '],
         [' ', 'x', ' '],
         [' ', ' ', 'o']]
the output should be TicTacToe(board) = ' ', since there are no three consecutive 'x's or 'o's diagonally, horizontally, or vertically.

[input] array.array.char board

A 3 × 3 tic-tac-toe board consisting of 'x', 'o' and ' ' symbols.
It is guaranteed that there is no more than one winner in the game.
[output] char

The winning side ('x' or 'o'). If neither side has won, return a space character (' ').
*/

#include <iostream>
#include <vector>

using namespace std;

char TicTacToe(std::vector<std::vector<char>> b)
{

    int n = b.size();
    for (int j = 0; j < n; j++)
    {
        if (b[j][0] == b[j][1] && b[j][0] == b[j][2] && b[j][0] != ' ')
            return b[j][0];
        if (b[0][j] == b[1][j] && b[0][j] == b[2][j] && b[0][j] != ' ')
            return b[0][j];
    }

    if (b[0][0] == b[1][1] && b[0][0] == b[2][2] && b[0][0] != ' ')
        return b[0][0];
    if (b[2][0] == b[1][1] && b[2][0] == b[0][2] && b[2][0] != ' ')
        return b[2][0];

    return ' ';

}


int main()
{
    std::vector<std::vector<char>> board =
    {
        {' ', 'x', 'o'},
        {' ', 'x', ' '},
        {' ', 'x', 'o'}
    };
    cout << TicTacToe(board) << endl;
    return 0;
}
