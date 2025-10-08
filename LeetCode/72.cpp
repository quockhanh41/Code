/**
 * @file 72.cpp
 * @author quockhanh41
 * @date 2025-10-02 00:45
 */

#include <iostream>
#include <vector>
using namespace std;
int minDistance(string word1, string word2)
{
    int dp[501][501] = {0};
    int m = word1.size();
    int n = word2.size();

    dp[0][0] = word1[0] != word2[0];
    int i = 0, j = 0;
    while (i < m || j < n)
    {
        if (word1[i] == word2[j])
            dp[i][j] = dp[i - 1][j];
        else
            dp[i][j] = dp[i - 1][j] + 1;
        if (i + 1 < m)
            i++;
        if (j + 1 < n)
            j++;
        if(i == m && j == n) break;
        cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
    }

    return dp[m - 1][n - 1];
}
int main()
{

    cout << minDistance("intention", "execution");
    return 0;
}