#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arrayPairSum(std::vector<int> &nums)
{
    int res = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 1; i += 2)
    {
        res += min(nums[i], nums[i + 1]);
    }
    return res;
}
