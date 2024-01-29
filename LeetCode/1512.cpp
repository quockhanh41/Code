#include <iostream>
#include <vector>
#include <map>
using namespace std;
int numIdenticalPairs(vector<int> &nums)
{
    int res = 0;
    map<int, bool> used;
    map<int, int> cnt;
    for (int i = 0; i < nums.size(); i++)
    {
        cnt[nums[i]]++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!used[nums[i]])
        {
            used[nums[i]] = 1;
            res += (cnt[nums[i]] * (cnt[nums[i]] - 1)) / 2;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}