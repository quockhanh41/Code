#include <iostream>
#include <vector>
using namespace std;
int cnt[10000];
int backtrack(vector<int> &toppingCosts, int target, int sum, int index)
{
    if (cnt[index] == 2)
    {
        return max(backtrack(toppingCosts, target, sum + toppingCosts[index], index), backtrack(toppingCosts, target, sum + toppingCosts[index], index));
    }
}
int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
{
    int res = 0;
    for (int i = 0; i < baseCosts.size(); i++)
    {
        res = max(res, backtrack(baseCosts, toppingCosts, target, 0, i, 0));
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}