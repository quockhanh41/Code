#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maximumProduct(vector<int> &nums)
{
    int n = nums.size();
    if (n == 3)
        return nums[0] * nums[1] * nums[2];
    int res = INT_MIN;
    sort(nums.begin(), nums.end());
    int a[] = {nums[0], nums[1], nums[n - 2], nums[n - 1]};
    return max(max(a[0] * a[1] * a[2], a[0] * a[1] * a[3]), max(a[3] * a[1] * a[2], a[0] * a[3] * a[2]));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}