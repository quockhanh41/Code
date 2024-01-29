#include <iostream>
#include <vector>
#include <string>
using namespace std;
string truncateSentence(string s, int k)
{
    s += " ";
    int i = 0;
    while (k)
    {
        if (s[i++] == ' ')
            k--;
    }

    return s.substr(0, i - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << truncateSentence("Hello how are you Contestant", 4);
    return 0;
}