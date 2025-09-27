#include <iostream>
#include <vector>
using namespace std;
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    if (n == 3)
        return max(max(nums[0], nums[1]), nums[2]);

    int *f = new int[n];

    // truong hop1: khong cuop nha 0
    f[0] = 0;
    f[1] = nums[1];
    for (int i = 2; i < n; i++)
    {
        f[i] = max(f[i - 2] + nums[i], f[i - 1]);
    }
    int res = f[n - 1];

    f[0] = nums[0];
    f[1] = max(f[0], nums[1]);

    for (int i = 2; i < n - 1; i++)
    {
        f[i] = max(f[i - 2] + nums[i], f[i - 1]);
    }
    res = max(res, f[n - 2]);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {1, 2, 3, 1};
    cout << rob(a);
    return 0;
}