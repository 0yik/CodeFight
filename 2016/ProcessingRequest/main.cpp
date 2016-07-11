#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i = 0, s = 0;
    vector<int> requests({1,2,7,8,9,10});
    int servers = 3;

    while(servers*2 >= requests[i] && i < requests.size())
    {
        s++;
        i++;
    }

    return (s > servers) ? servers : s;
}
