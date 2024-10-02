#include <iostream>
#include <vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (obstacleGrid[i - 1][j - 1] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    // for (int i = 0; i <= m; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[m][n];
}
int main()
{
    vector<vector<int>> a = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    cout << uniquePathsWithObstacles(a);
    return 0;
}
