#include <iostream>
using namespace std;
    bool halvesAreAlike(string s)
    {
        int n = s.size() / 2;
        int cnt1[256] = {};
        int cnt2[256] = {};
        int sum1 = 0;
        int sum2 = 0;

        for (int i = 0; i < n; i++)
        {
            cnt1[s[i]]++;
        }
        for (int i = n; i < s.size(); i++)
        {
            cnt2[s[i]]++;
        }
        string tar = "ueoaiUEOAI";
        for (int i = 0; i < tar.size(); i++)
        {
            sum1 += cnt1[tar[i]];
            sum2 += cnt2[tar[i]];
        }
        return sum1 == sum2;
    }
int main()
{
    cout << halvesAreAlike("textbook");
    return 0;
}