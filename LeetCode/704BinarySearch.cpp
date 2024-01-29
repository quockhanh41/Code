#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (r + l) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
int main()
{
    vector<int> a = {-1, 0, 3, 5, 9, 12};
    cout << search(a, 2);
}
