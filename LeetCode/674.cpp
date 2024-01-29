#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findLengthOfLCIS(vector<int> &nums)
{

    int n = nums.size();
    vector<int> cnt = nums;
    cnt[0] = 1;
    for (int i = 1; i < n; i++)
    {
        // cout << nums[i] << " " << nums[i - 1] << endl;
        if (nums[i] > nums[i - 1])
            cnt[i] = cnt[i - 1] + 1;
        else
            cnt[i] = 1;
    }
    return *max_element(cnt.begin(), cnt.end());
}
int main()
{
    vector<int> nums = {1, 3, 5, 4, 7, 8, 9};
    cout << findLengthOfLCIS(nums);
}