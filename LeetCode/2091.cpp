#include <iostream>
#include <vector>
using namespace std;
int minimumDeletions(vector<int> &nums)
{
    int a = 0;
    int b = 0;
    int ans = INT_MAX;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[b])
            b = i;
        if (nums[i] < nums[a])
            a = i;
    }
    if (a > b)
        swap(a, b);
    ans = min(n - a, b + 1);
    ans = min(a + 1 + n - b, ans);
    return ans;
}
int main()
{
    vector<int> a = {2, 10, 7, 5, 4, 1, 8, 6};
    cout << minimumDeletions(a);
}