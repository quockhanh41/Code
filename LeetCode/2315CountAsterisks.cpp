#include <iostream>
using namespace std;
int countAsterisks(string s)
{
    int count = 0;
    int res = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '|')
            count++;
        if (count % 2 != 0)
            continue;
        if (s[i] == '*')
            res++;
    }
    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << countAsterisks(s);
}