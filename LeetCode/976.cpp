#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int largestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), greater());
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (nums[i + 2] > nums[i] - nums[i - 1])
            return nums[i] + nums[i + 1] + nums[i + 2];
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}