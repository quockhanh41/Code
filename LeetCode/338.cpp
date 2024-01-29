#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n)
{
    vector<int> res;
    int dp[(int)1e5] = {0, 1};
    res.push_back(0);
    if (n == 0)
        return res;
    res.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i / 2] + i % 2;
        res.push_back(dp[i]);
    }
    return res;
}
// climb stair dynamic programming
int main()
{
    for (auto x : countBits(5))
        cout << x << " ";
}