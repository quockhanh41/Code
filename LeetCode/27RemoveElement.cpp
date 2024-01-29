#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    if (find(nums.begin(), nums.end(), target) == nums.end())
    {
        nums.push_back(target);
        sort(nums.begin(), nums.end());
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
            return i;
    }
}