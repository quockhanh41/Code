#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
    vector<vector<int>> res;
    // luu ds cac ng choi
    set<int> ds;
    int cntlost[10000] = {0};
    for (int i = 0; i < matches.size(); i++)
    {
        ds.insert(matches[i][0]);
        ds.insert(matches[i][1]);
        cntlost[matches[i][1]]++;
    }
    vector<int> nguoi(ds.begin(), ds.end());
    vector<int> dslost0;
    vector<int> dslost1;
    for (int i = 0; i < nguoi.size(); i++)
    {
        if (cntlost[nguoi[i]] == 0)
            dslost0.push_back(nguoi[i]);
        if (cntlost[nguoi[i]] == 1)
            dslost1.push_back(nguoi[i]);
    }
    sort(dslost0.begin(), dslost0.end());
    sort(dslost1.begin(), dslost1.end());
    res.push_back(dslost0);
    res.push_back(dslost1);
    return res;
}
int main()
{
    vector<vector<int>> a = {{2, 3}, {1, 3}, {5, 4}, {6, 4}};
    for (auto x : findWinners(a))
        for (auto y : x)
            cout << y << " ";
}