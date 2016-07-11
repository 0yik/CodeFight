#include <iostream>

using namespace std;

std::string coolString(string inputString);

int main()
{
    cout << coolString("aAaAaAaAbCBB");
    return 0;
}

std::string coolString(std::string inputString)
{

    bool state = false;
    int x, y;
    char c;
    char d;

    int n = inputString.length();

    for (x = 0; x < n-1; x++)
    {
        y = x + 1;
        if(isupper(inputString.at(x)))
        {
            if(islower(inputString.at(y)))
            {
                state = true;
            }
            else
            {
                state = false;

            }
        }

        if(islower(inputString.at(x)))
        {
            if(isupper(inputString.at(y)))
            {
                state = true;
            }
            else
            {
                state = false;

            }
        }
    }

    if(state)
    {
        return "benar";
    }
    else
    {
        return "salah";
    }

}
