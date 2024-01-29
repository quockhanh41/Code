#include <iostream>
#include <vector>

using namespace std;
bool isIsomorphic(string s, string t)
{
    string res = "";
    int n = s.size();
    int m = t.size();
    int f[256] = {0};
    bool used[256] = {0};
    if (m != n)
        return false;
    for (int i = 0; i < n; i++)
    {
        if (f[s[i]] == 0 && used[t[i]] == 0)
        {
            f[s[i]] = t[i];
            used[t[i]] = 1;
        }
        res += f[s[i]];
    }

    return res == t;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}