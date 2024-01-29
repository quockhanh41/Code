#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n = nums.size();
    int sum = 0;
    int res = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (sum < 0)
            sum = 0;
        sum += nums[i];
        res = max(res, sum);
    }
    return res;
}
int main()
{
    vector<int> a = {5, 4, -1, 7, 8};
    cout << maxSubArray(a);
}