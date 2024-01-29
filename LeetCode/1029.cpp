#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] - a[0] < b[1] - b[0];
}

int twoCitySchedCost(vector<vector<int>> &costs)
{
    int res = 0;
    sort(costs.begin(), costs.end(), cmp);
    int n = costs.size();
    for (int i = 0; i < n / 2; i++)
    {
        res += costs[i][1] + costs[i + n / 2][0];
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
    cout << twoCitySchedCost(costs);
    return 0;
}