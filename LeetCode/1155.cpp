#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;

int memo[31][1001]; // Adjust the size of the memoization table based on the constraints

int solve(int n, int k, int target)
{
    if (target < 0)
        return 0;
    if (n == 0)
    {
        return (target == 0) ? 1 : 0;
    }
    if (memo[n][target] != -1)
    {
        return memo[n][target];
    }

    int count = 0;
    for (int i = 1; i <= k; i++)
    {
        count += solve(n - 1, k, target - i);
        count %= mod;
    }

    memo[n][target] = count;
    return count;
}
int numRollsToTarget(int n, int k, int target)
{
    memset(memo, -1, sizeof(memo)); // Initialize memoization table with -1
    return solve(n, k, target);
}
int main()
{
    // memset(memo, -1, sizeof(memo)); // Initialize memoization table with -1
    int n, k, target;
    cin >> n >> k >> target;
    int ways = numRollsToTarget(n, k, target);
    cout << ways << endl;
    return 0;
}
