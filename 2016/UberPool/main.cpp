#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> A({0,0}), B({3,3}), C({3,1}), X({5,0}), Y({2,2});
    int ruteB, ruteX, ruteY, ruteC;
    ruteB=ruteX=ruteY= 0;

    ruteB = abs(B[0]-A[0]) + abs(B[1]-A[1]);
    ruteC = abs(C[0]-A[0]) + abs(C[1]-A[1]);
    ruteX = abs(X[0]-C[0]) + abs(X[1]-C[1]) + abs(B[0]-X[0]) + abs(B[1]-X[1]);
    ruteY = abs(Y[0]-C[0]) + abs(Y[1]-C[1]) + abs(B[0]-Y[0]) + abs(B[1]-Y[1]);

    if (ruteB * 2 > ruteC+ruteX || ruteB * 2 > ruteC+ruteY)
    {
        if (ruteB * 2 > ruteC+ruteX) return 1;
        if (ruteB * 2 > ruteC+ruteY) return 2;
    }

    return -1;
}
