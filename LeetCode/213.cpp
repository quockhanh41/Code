#include <iostream>
#include <vector>
using namespace std;
int rob(vector<int> &nums)
{
    bool check = 0;
    int n = nums.size();
    int *f = new int[n];
    f[0] = nums[0];
    f[1] = nums[1];
    for (int i = 2; i < n; i++)
    {
        if (i == 2)
        {
            if (f[i - 2] + nums[i] > f[i - 1])
            {
                check = 1;
            }
        }
        if (i == n - 1 && check == 1)
        {
            f[n - 1] = f[n - 2];
        }
        else
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
    }
    return f[n - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {1, 2, 3};
    cout << rob(a);
    return 0;
}