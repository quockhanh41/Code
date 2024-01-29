#include <iostream>
#include <vector>
using namespace std;
int findNumberOfLIS(vector<int> &nums)
{
    int cnt[256] = {0};
    int res = 1;
    int maxLength = 1;
    int n = nums.size();
    int dp[2001] = {1};
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > maxLength)
            break;
        else
            cnt[dp[i]]++;
    }

    for (int i = maxLength; i >= 1; i--)
    {
        if (cnt[i] == 0)
            break;
        else
            res *= cnt[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }

    cout << endl;

    return res;
}
int main()
{
    vector<int> a = {1, 2, 4, 3, 5, 4, 7, 2};
    cout << findNumberOfLIS(a);
}