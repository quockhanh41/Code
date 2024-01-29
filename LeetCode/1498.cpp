#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int mod = 1000000007;
int numSubseq(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int res = 0;
    int n = nums.size();
    vector<int> pow2(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        pow2[i] = (2 * pow2[i - 1]) % mod;
    }
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        if (nums[l] + nums[r] <= target)
        {
            res = (res + pow2[r - l]) % mod;
            l++;
        }
        else
            r--;
    }
    return res;
}
int main()
{
    vector<int> a = {14, 4, 6, 6, 20, 8, 5, 6, 8, 12, 6, 10, 14, 9, 17, 16, 9, 7, 14, 11, 14, 15, 13, 11, 10, 18, 13, 17, 17, 14, 17, 7, 9, 5, 10, 13, 8, 5, 18, 20, 7, 5, 5, 15, 19, 14};
    cout << numSubseq(a, 22);
}
