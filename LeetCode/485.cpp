#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O2")
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i])
        {
            cnt++;
        }
        else
        {
            res = max(res, cnt);
            cnt = 0;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {0, 1, 0, 1};
    cout << findMaxConsecutiveOnes(a);
    return 0;
}
