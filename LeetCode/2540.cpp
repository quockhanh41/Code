#include <iostream>
#include <vector>
using namespace std;
int getCommon(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0;
    int j = 0;
    int n1 = nums1.size();
    int n2 = nums2.size();

    while (i < n1 && j < n2)
    {
        if (nums1[i] == nums2[j])
            return nums1[i];
        else if (nums1[i] > nums2[j])
            j++;
        else
            i++;
    }
    return -1;
}
int main()
{
    vector<int> a = {1, 2, 3, 6};
    vector<int> b = {2, 3, 4, 5};
    cout << getCommon(a, b);
}