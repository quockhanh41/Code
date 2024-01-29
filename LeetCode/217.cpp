#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool containsDuplicate(vector<int> &nums)
{
    map<int, bool> cnt;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (cnt[nums[i]] == 0)
            cnt[nums[i]] = 1;
        else
            return 1;
    }
    return 0;
}
int main()
{
}