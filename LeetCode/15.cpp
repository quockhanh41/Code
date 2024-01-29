#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> t;
    int l = 0, r = nums.size() - 1, m = 1;
    while (m < r)
    {
        if (nums[l] + nums[m] + nums[r] == 0)
        {
            t.push_back(nums[l]);
            t.push_back(nums[m]);
            t.push_back(nums[r]);
            res.push_back(t);
        }
        else if ()
    }
}
int main()
{
}