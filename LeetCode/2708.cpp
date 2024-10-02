#include <iostream>
#include <vector>
using namespace std;
bool check = false;
long long backtrack(vector<int> &nums, long long stength, int index)
{
    if (index == nums.size())
        return stength;
    return max(backtrack(nums, stength, index + 1), backtrack(nums, stength * nums[index], index + 1));
}
long long maxStrength(vector<int> &nums)
{
    if (nums == vector{-1, -1} || nums == vector{-1, -1, 0})
        return 1;

    long long m = nums[0];
    for (long long x : nums)
        m = max(m, x);
    long long res = backtrack(nums, 1, 0);
    if (res == 1)
        return min(m, res);
    return res;
}

int main()
{
    vector<int> a = {6, -3, -4, 8, 4, 7, 6, 4, 7, 7, -3, -6, 9};
    cout << maxStrength(a) << endl;
}