#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int res = nums[0];
    for (int i = 1; i < n - 1; i++)
    {
        res = max(res - 1, nums[i]);
    }
    return res >= 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}