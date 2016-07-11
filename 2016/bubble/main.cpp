#include <iostream>
#include <array>

using namespace std;

int main()
{

    int arr[] = {3,2,1,4,7,6};
    int n = 6;
    int i = 0;
    bool sw;
    do
    {
        sw = false;
        for (int x = 1; x <= n-1; x++)
        {
            if (arr[x-1] > arr[x])
            {
                std::swap(arr[x-1],arr[x]);
                sw = true;
            }
        }

        for (int x = 1; x <= 6; x++)
        {
            cout << to_string(arr[x-1]) + ",";
        }

        i++;

        cout << to_string(i);
        cout << "\n";
    }
    while(sw);



}
