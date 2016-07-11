#include <iostream>
#include <vector>

using namespace std;

std::vector<int> closestNeighbor(int n, int a, int b, int c) {

    int x,y,i,j,k;
    std::vector<int> p;

    x = n;
    y = n;

    y--;
    i = y % a;
    j = y % b;
    k = y % c;


    while(i != 0 || j != 0 || k != 0)
    {
        y--;
        i = y % a;
        j = y % b;
        k = y % c;
    }

    x++;
    i = x % a;
    j = x % b;
    k = x % c;

    while(i != 0 || j != 0 || k != 0)
    {
        x++;
        i = x % a;
        j = x % b;
        k = x % c;
    }

    p.push_back(y);
    p.push_back(x);

    return p;
}


int main()
{
    std::vector<int> p = closestNeighbor(10,2,5,10);
    for(int i = 0; i < p.size(); i++)
    cout << p[i] << endl;
    return 0;
}
