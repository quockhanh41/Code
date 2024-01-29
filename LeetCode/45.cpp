#include <iostream>
#include <vector>
using namespace std;
int jump(vector<int> &nums)
{

    int jumps = 0;

    int curReach = 0;
    int curMax = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (i + nums[i] > curMax)
        {
            curMax = i + nums[i];
        }

        if (i == curReach)
        {
            jumps++;
            curReach = curMax;
        }
        cout << curMax << " " << curReach << " " << jumps << endl;
    }

    return jumps;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums);
    return 0;
}