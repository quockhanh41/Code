#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
map<pair<int, int>, bool> used;
set<vector<int>> res;
int a[100];
vector<int> v;
void backtrack(vector<int> nums, int index)
{
    int n = nums.size();
    if (index == n)
    {
        for (int i = 0; i < n; i++)
        {
            v.push_back(a[i]);
        }
        res.insert(v);
        v.clear();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!used[{nums[i], i}])
        {
            used[{nums[i], i}] = 1;
            a[index] = nums[i];
            backtrack(nums, index + 1);
            used[{nums[i], i}] = 0;
        }
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    backtrack(nums, 0);
    vector<vector<int>> ans(res.begin(), res.end());
    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 3};
    for (auto x : permuteUnique(nums))
    {
        for (auto v : x)
            cout << v << " ";
        cout << endl;
    }
    // vector<vector<int>> a = {{1, 1}, {1, 2}, {1, 2}};
    // set<vector<int>> b(a.begin(), a.end());
    // for (auto x : b)
    // {
    //     for (auto v : x)
    //         cout << v << " ";
    //     cout << endl;
    // }
}