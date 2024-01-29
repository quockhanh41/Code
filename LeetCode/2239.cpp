#include <iostream>
#include <vector>
using namespace std;
int findClosestNumber(vector<int> &nums)
{
    int n = nums.size();
    int res = nums[0];
    int record = abs(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (abs(nums[i]) < record)
        {
            res = nums[i];
            record = abs(nums[i]);
        }
        else if (abs(nums[i]) == record)
            res = max(res, nums[i]);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {-4, -2, 1, 4, 8};
    cout << findClosestNumber(a);
    return 0;
}