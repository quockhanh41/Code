#include <iostream>
using namespace std;
    string longestPalindrome(string s)
{
    string res = "";
    bool L[1001][1001] = {0};
    int n = s.size();
    s = "x" + s;
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            if (len <=2 && s[i] == s[j])
                L[i][j] = 1;
            else if (s[i] == s[j])
                L[i][j] = L[i + 1][j - 1];
            if (L[i][j])
            {
                string ans = "";
                for (int a = i; a <= j; a++)
                {
                    ans += s[a];
                }
                if (ans.size() > res.size())
                    res = ans;
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << L[i][j] << " ";
    //     cout << endl;
    // }

    return res;
}
int main()
{
    cout << longestPalindrome("a");
}