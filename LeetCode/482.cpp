#include <iostream>
#include <vector>
using namespace std;
string licenseKeyFormatting(string s, int k)
{
    string ans = "";
    string res = "";
    int count = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] != '-')
        {
            res += toupper(s[i]);
            count++;
            if (count == k )
            {
                res += "-";
                count = 0;
            }
        }
    }
    if (!res.empty())
    {
        if (res[res.size() - 1] == '-')
            res.erase(res.size() - 1);
    }
    for (int i = res.size() - 1; i >= 0; i--)
    {
        ans += res[i];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << licenseKeyFormatting("---", 3);
    return 0;
}