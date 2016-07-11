#include <iostream>

using namespace std;

int main()
{
    string word = "abiryz";
    char a,b;
    if (word.length()%2 == 0)
    {
        for (int i = 0; i < word.length()/2; i++)
        {
            a = word.at(i)-96;
            b = word.at(word.length() - i - 1)-96;

            if (a + b != 27) return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}
