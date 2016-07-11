#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::string Expand_It(std::string s, int k)
{

    double x = 0;
    int z = s.size();
    std::string val = "", y,l = "";


    y = s[0];
    for (double i = 0; i < z; i++)
    {
        if ((s[i] - 48) > 9)
        {
            for (int w = 0; w < l.size(); w++)
            {
                x += (l[w] - 48) * pow(10, (l.size()- w - 1));
            }

            for(double n = 0; n < x; n++)
            {
                val += y;
            }
            y = s[i];
            x = 0;
            l = "";
        }
        else
        {
            l += s[i];
        }
    }

    for (int w = 0; w < l.size(); w++)
    {
        x += (l[w] - 48) * pow(10, (l.size()- w - 1));
    }

    for(long int n = 0; n < x; n++)
    {
        val += y;
    }

    std::sort(val.begin(), val.end());
    if(val.size() < k) return "-1";
    val = val[k-1];
    return val;
}


int main()
{
    cout << Expand_It("a2b3c2a1", 8) << endl;
    return 0;
}
