#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
string frequencySort(string s)
{
    string res = "";
    vector<int> v;
    int cnt[256] = {};
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i]]++;
    }
    for (int i = '0'; i <= 'z'; i++)
    {
        v.push_back(cnt[i]);
    }
    set<int> a(v.begin(), v.end());
    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end(), greater());
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = '0'; j <= 'z'; j++)
        {
            if (cnt[j] == b[i])
                for (int k = 0; k < b[i]; k++)
                {
                    res += (char)j;
                }
        }
    }
    return res;
}
int main()
{
    cout << frequencySort("2a554442f544asfasssffffasss");
}