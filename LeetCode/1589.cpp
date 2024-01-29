#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
{
    int mod = 1e9 + 7;
    int res = 0;
    int n = nums.size();
    int frequency[50001] = {0};
    for (auto x : requests)
        for (int i = x[0]; i <= x[1]; i++)
            frequency[i]++;
    sort(frequency, frequency + n, greater());
    sort(nums.begin(), nums.end(), greater());
    for (int i = 0; i < n; i++)
    {
        res %= mod;
        res += nums[i] * frequency[i];
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}