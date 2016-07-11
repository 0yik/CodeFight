/*You are given a n x m matrix, which contains all the integers from 1 to n * m, inclusive, each exactly once.

Initially you are standing in the cell containing the number 1. On each turn you are allowed to move to an adjacent cell, i.e. to a cell that shares a common side with the one you are standing on now. It is prohibited to visit any cell more than once.

Check if it is possible to visit all the cells of the matrix in the order of increasing numbers in the cells, i.e. get to the cell with the number 2 on the first turn, then move to 3, etc.

Example

findPath([[1, 4, 5],
          [2, 3, 6]]) = true

findPath([[1, 3, 6],
          [2, 4, 5]]) = false*/

#include <iostream>
#include <vector>

using namespace std;

bool findPath(std::vector< std::vector< int > > matrix) {

    int x,y,a,b,c=1;

    x = matrix.size()-1;
    y = matrix[0].size()-1;

    for (int j = 0; j <= x; j++)
    {
        if (matrix[j].at(0) == 1)
        {
            a = j;
            b = 0;
        }
    }

    for (int j = 2; j <= matrix[0].size()*matrix.size(); j++)
    {
        if (a == 0 && b == 0)
        {
            if (matrix[a+1][b] == j)
            {
                a += 1;
                c += 1;
            }
            if (matrix[a][b+1] == j)
            {
                b += 1;
                c += 1;
            }
        }
        if (a == 0 && b == y)
        {
            if (matrix[a+1][b] == j)
            {
                a += 1;
                c += 1;
            }
            if (matrix[a][b-1] == j)
            {
                b -= 1;
                c += 1;
            }
        }
        if (a == x && b == 0)
        {
            if (matrix[a-1][b] == j)
            {
                a -= 1;
                c += 1;
            }
            if (matrix[a][b+1] == j)
            {
                b += 1;
                c += 1;
            }
        }
        if (a == x && b == y)
        {
            if (matrix[a-1][b] == j)
            {
                a -= 1;
                c += 1;
            }
            if (matrix[a][b-1] == j)
            {
                b -= 1;
                c += 1;
            }
        }
        if (a == x && b < y && b > 0)
        {
            if (matrix[a-1][b] == j)
            {
                a -= 1;
                c += 1;
            }
            if (matrix[a][b+1] == j)
            {
                b += 1;
                c += 1;
            }
            if (matrix[a][b-1] == j)
            {
                b -= 1;
                c += 1;
            }
        }
        if (b == y && a < x && a > 0)
        {
            if (matrix[a-1][b] == j)
            {
                a -= 1;
                c += 1;
            }
            if (matrix[a+1][b] == j)
            {
                a += 1;
                c += 1;
            }
            if (matrix[a][b-1] == j)
            {
                b -= 1;
                c += 1;
            }
        }
        if (a == 0 && b < y && b > 0)
        {
            if (matrix[a+1][b] == j)
            {
                a += 1;
                c += 1;
            }
            if (matrix[a][b+1] == j)
            {
                b += 1;
                c += 1;
            }
            if (matrix[a][b-1] == j)
            {
                b -= 1;
                c += 1;
            }
        }
        if (b == 0 && a < x && a > 0)
        {
            if (matrix[a-1][b] == j)
            {
                a -= 1;
                c += 1;
            }
            if (matrix[a+1][b] == j)
            {
                a += 1;
                c += 1;
            }
            if (matrix[a][b+1] == j)
            {
                b += 1;
                c += 1;
            }
        }

        if (a > 0 && a < x && b > 0 && b < y)
        {
            if (matrix[a+1][b] == j)
            {
                a += 1;
                c += 1;
            }
            if (matrix[a-1][b] == j)
            {
                a -= 1;
                c += 1;
            }
            if (matrix[a][b+1] == j)
            {
                b += 1;
                c += 1;
            }
            if (matrix[a][b-1] == j)
            {
                b -= 1;
                c += 1;
            }
        }

    }

    if (c == matrix[0].size()*matrix.size()) return true;
    return false;
}


int main()
{
std::vector< std::vector< int > > matrix { {1,2,3,12,13,18},
                                            {6,5,4,11,14,17},
                                            {7,8,9,10,15,16} };
    if(findPath(matrix)) cout << "benar";
     else cout << "salah";
}
