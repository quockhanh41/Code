#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums)
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (nums.size() == 1)
        return 0;
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (mid == 0)
        {
            if (nums[mid] > nums[mid + 1])
                return mid;
            l = mid + 1;
        }
        else if (mid == nums.size() - 1)
        {
            if (nums[mid] > nums[mid - 1])
                return mid;
            r = mid - 1;
        }
        else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        else if (nums[mid] < nums[mid + 1])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {1, 2};
   cout << findPeakElement(a);
    return 0;
}