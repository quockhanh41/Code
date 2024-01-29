#include <iostream>
using namespace std;
string gcdOfStrings(string str1, string str2)
{
    string res = "";
    string s = "";

    int n = str2.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        s += str2[i];
        string p = "";
        for (int i = 0; i < str2.size() / s.size(); i++)
        {
            p += s;
        }
        if (str2 == p)
            cnt++;
        p = "";
        for (int i = 0; i < str1.size() / s.size(); i++)
        {
            p += s;
        }
        if (str1 == p)
            cnt++;
        if (cnt == 2 && p.size() > res.size())
            res = s;
    }
    return res;
}
int main()
{
    string str1 = "ABABAB", str2 = "ABAB";
    cout << gcdOfStrings(str1, str2);
    return 0;
}