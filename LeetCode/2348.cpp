#include <iostream>
#include <vector>
using namespace std;
long long zeroFilledSubarray(vector<int> &nums)
{
    nums.push_back(1);
    long long res = 0;
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            cnt++;
        else if (nums[i] != 0)
        {
            if (cnt % 2 == 0)
                res += (cnt / 2 * (cnt + 1));
            else
                res += ((cnt + 1) / 2 * cnt);
            cnt = 0;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {0, 0, 0, 2, 0, 0};
    zeroFilledSubarray(a);
    return 0;
}