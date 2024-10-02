#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int> &nums, int target, int sum, int index, int &res)
{
    if (index == nums.size())
    {
        if (sum == target)
            res++;
        return;
    }
    backtrack(nums, target, sum + nums[index], index + 1, res);
    backtrack(nums, target, sum - nums[index], index + 1, res);
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int res = 0;
    backtrack(nums, target, 0, 0, res);
    return res;
}
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << findTargetSumWays(nums, target) << endl;

    return 0;
}