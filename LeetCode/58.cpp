#include <iostream>
using namespace std;
int lengthOfLastWord(string s)
{
    int res = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
            res++;
        if (s[i] != ' ' && s[i - 1] == ' ')
            break;
    }
    return res;
}
int main()
{
}