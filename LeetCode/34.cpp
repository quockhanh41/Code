#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int> &nums, int target)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> res(2);
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
        {
            int s = mid, e = mid;
            while (s - 1 >= 0 && nums[s - 1] == target)
                s--;
            while (e + 1 <= nums.size() - 1 && nums[e + 1] == target)
                e++;
            return {s, e};
        }
        else if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return {-1, -1};
}
int main()
{

    return 0;
}