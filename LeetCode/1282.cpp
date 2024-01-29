#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> groupThePeople(vector<int> &groupSizes)
{
    vector<vector<int>> res;
    int n = groupSizes.size();
    vector<vector<int>> gr(501);
    for (int i = 0; i < n; i++)
    {
        if (gr[groupSizes[i]].size() < groupSizes[i])
            gr[groupSizes[i]].push_back(i);
        else
        {
            res.push_back(gr[groupSizes[i]]);
            gr[groupSizes[i]].clear();
            gr[groupSizes[i]].push_back(i);
        }
    }
    for (auto x : gr)
        if (!x.empty())
            res.push_back(x);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}