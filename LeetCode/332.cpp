#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    sort(coins.begin(), coins.end());
    int res = 0;
    int i = coins.size() - 1;
    while (i >= 0 && amount > 0)
    {
        if (amount >= coins[i])
        {
            cout << amount << " " << coins[i] << endl;
            amount -= coins[i];
            res++;
        }
        else
            i--;
    }
    cout << amount;
    if (amount == 0)
        return res;
    return -1;
}
int main()
{
    vector<int> a = {186, 419, 83, 408};
    cout << coinChange(a, 6249);
}