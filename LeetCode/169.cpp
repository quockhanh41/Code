#include <iostream>
#include <vector>
#include <map>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int n = nums.size() / 2;
    map<int, int> m;
    for (auto x : nums)
    {
        m[x]++;
        if (m[x] > n)
            return x;
    }
    return -1;
}
int firstUniqChar(string s)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cnt[256] = {0};
    int n = s.size();
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 0; i < n; i++)
    {
        if (cnt[s[i]] == 1)
            return i;
    }
    return -1;
}
int main()
{
}