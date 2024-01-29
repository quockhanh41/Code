#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n = nums1.size(), m = nums2.size(), l1 = 0, l2 = 0;
    vector<int> res;

    while (l1 < n || l2 < m)
    {
        if (nums1[l1] == nums2[l2])
        {
            res.push_back(nums1[l1++]);
            l2++;
        }
        else if (nums1[l1] < nums2[l2])
            l1++;
        else
            l2++;
    }
    return res;
}
int main()
{
}