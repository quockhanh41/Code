#include <iostream>
#include <vector>
#include <map>
using namespace std;
// int binSearch(vector<int> &nums, int l, int r, int target)
// {
//     while (l <= r)
//     {
//         int mid = (l + r) / 2;
//         if (nums[mid] < target)
//             l = mid + 1;
//         else if (nums[mid] > target)
//             r = mid - 1;
//         else
//             return mid;
//     }
//     return -1;
// }
// int mid(vector<int> &nums)
// {
//     int s = 0;
//     int e = nums.size() - 1;
//     int mid = s + (e - s) / 2;
//     while (s < e)
//     {
//         if (nums[mid] > nums[e])
//         {
//             s = mid + 1;
//         }
//         else
//         {
//             e = mid;
//         }
//         mid = s + (e - s) / 2;
//     }
//     return s;
// }
// int search(vector<int> &nums, int target)
// {
//     int pivot = mid(nums);
//     if (binSearch(nums, 0, pivot - 1, target) != -1)
//         return binSearch(nums, 0, pivot - 1, target);
//     if (binSearch(nums, pivot, nums.size() - 1, target) != -1)
//         return binSearch(nums, pivot, nums.size() - 1, target);
//     return -1;
// }
int search(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        cout << nums[l] << " " << nums[mid] << " " << nums[r] << endl;
        if (nums[mid] == target)
            return mid;
        else if (target < nums[mid])
        {
            if (nums[l] < nums[r])
            {
                r = mid - 1;
                continue;
            }
            if (target >= nums[l])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (nums[l] < nums[r])
            {
                l = mid + 1;
                continue;
            }
            if (target > nums[l])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> a = {4, 5, 6, 7, 0, 1, 2};
    cout << search(a, 0);
}