#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
bool binSearch(vector<int> &nums, int x, int l, int r)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] > x)
            r = mid - 1;
        else if (nums[mid] < x)
            l = mid + 1;
        else
            return 1;
    }
    return 0;
}
int longestSquareStreak(vector<int> &nums)
{
    int n = nums.size();
    int dp[(int)1e5];
    for (int i = 0; i <= nums[n - 1]; i++)
    {
        dp[i] = 1;
    }

    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i++)
    {
        if (sqrt(nums[i]) == int(sqrt(nums[i])))
            dp[nums[i]] = dp[int(sqrt(nums[i]))] + binSearch(nums, sqrt(nums[i]), 0, i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[nums[i]] << " ";
    }
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        if (dp[nums[i]] > res)
            res = dp[nums[i]];
    }

    if (res == 1)
        return -1;
    else
        return res;
}
int main()
{
    vector<int> a = {2, 3, 5, 6, 7};
    cout << longestSquareStreak(a);
}