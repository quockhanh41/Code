#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    int *f = new int[amount + 1];
    for (int i = 1; i <= amount; i++)
    {
        f[i] = INT_MAX;
    }

    f[0] = 0;
    for (int i = coins.size() - 1; i >= 0; i--)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            if (f[j - coins[i]] != INT_MAX)
                f[j] = min(f[j], f[j - coins[i]] + 1);
        }
    }
    return f[amount] == INT_MAX ? -1 : f[amount];
}
int main()
{
    vector<int> a = {1, 2, 5};
    cout << coinChange(a, 11);
}