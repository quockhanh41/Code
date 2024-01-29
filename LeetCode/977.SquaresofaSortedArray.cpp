#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int t;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        t = nums[i];
        nums[i] = t * t;
    }
    sort(nums.begin(), nums.end());
    return nums;
}