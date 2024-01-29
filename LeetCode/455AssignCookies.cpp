#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0;
    int j = 0;
    for (int j = 0; j < s.size(); j++)
    {
        if (i < g.size() && g[i] <= s[j])
            i++;
    }
    return i;

    // while (j < s.size() && i < g.size())
    // {
    //     if (g[i] <= s[j])
    //         i++;
    //     j++;
    // }
    // return i;
}
int main()
{
    vector<int> a = {10, 9, 8, 7};
    vector<int> b = {5, 6, 7, 8};
    cout << findContentChildren(a, b);
}