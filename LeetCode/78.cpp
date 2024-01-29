#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
vector<int> v;
int arr[100];
int n;
void backtrack(vector<int> &nums, int index)
{
    if (index == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
                v.push_back(nums[i]);
        }
        res.push_back(v);
        v.clear();
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        arr[index] = i;
        backtrack(nums, index + 1);
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    n = nums.size();
    backtrack(nums, 0);
    return res;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    for (auto x : subsets(nums))
    {
        for (auto v : x)
            cout << v << " ";
        cout << endl;
    }
}