#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dominantIndex(vector<int> &nums)
{
    vector<int> a = nums;
    int n = nums.size();
    sort(a.begin(), a.end());
    if (a[n - 1] < a[n - 2] * 2)
        return -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == a[n - 1])
            return i;
    }
}
int main()
{
    vector<int> a = {3, 6, 1, 0};
    cout << dominantIndex(a);
}