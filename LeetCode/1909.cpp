#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;
bool isIncreasing(vector<int> nums, int index)
{
    nums.erase(nums.begin() + index);
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] >= nums[i + 1])
            return false;
    }
    return true;
}
bool canBeIncreasing(vector<int> &nums)
{
    int mistake = 0;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] >= nums[i + 1])
        {
            mistake++;
            if (mistake >= 2)
                return false;
            if (!isIncreasing(nums, i) && !isIncreasing(nums, i + 1))
                return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {1, 1, 1};

    cout << canBeIncreasing(a);

    return 0;
}