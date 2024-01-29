#include <iostream>
#include <vector>
using namespace std;
int getMaxLen(vector<int> &nums)
{
    int n = nums.size();
    pair<int, bool> dp[10001];
    if (nums[0] <= 0)
        dp[0] = {0, 0};
    else
        dp[0] = {1, 1};
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < 0 && dp[i - 1].second == 0)
        {
            dp[i].first = dp[i - 1].first + 2;
            dp[i].second = 1;
        }
        else if (nums[i] > 0 && dp[i - 1].second == 1)
        {
            dp[i].first = dp[i - 1].first + 1;
            dp[i].second = 1;
            dp[i].first = max(dp[i].first, 1);
        }
        else
        {
            dp[i].first = dp[i - 1].first;
            if (dp[i - 1].second + (nums[i] > 0) == 1)
                dp[i].second = 0;
            else
                dp[i].second = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[i].first << " " << dp[i].second << '\n';
    }

    return dp[n - 1].first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {0, 1, -2, -3, -4};
    cout << getMaxLen(a);
    return 0;
}