#include <iostream>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    bool used[255] = {0};
    int res = 0;
    int cnt = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (!used[s[i]])
        {
            used[s[i]] = 1;
            cnt++;
            res = max(res, cnt);
        }
        else
        {
            bool used[255] = {0};
            used[s[i]] = 1;
            cnt = 1;
        }
    }
    return res;
}
int main()
{
    cout << lengthOfLongestSubstring("dvdf");
}