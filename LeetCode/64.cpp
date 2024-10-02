#include <iostream>
#include <vector>
using namespace std;
int minPathSum(vector<vector<int>> &grid)
{
    vector<vector<int>> dp = grid;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
                continue;
            }
            int left = INT_MAX, up = INT_MAX;
            if (i >= 1)
                up = dp[i - 1][j];
            if (j >= 1)
                left = dp[i][j - 1];
            dp[i][j] = min(up, left) + grid[i][j];
        }
    }

    return dp[m - 1][n - 1];
}
int main()
{
    vector<vector<int>> dp = {{1, 2, 3}, {4, 5, 6}};
    cout << minPathSum(dp) << endl;
    return 0;
}
