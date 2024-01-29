#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<vector<int>> result;
void permutation(vector<int> &nums, int i, int n)
{
    if (i == n)
    {
        result.push_back(nums);
        return;
    }
    for (int j = i; j <= n; j++)
    {
        swap(nums[i], nums[j]);
        cout << i << " " << j << endl;
        permutation(nums, i + 1, n);
        cout << " " << i << " " << j << endl;
        swap(nums[i], nums[j]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    permutation(nums, 0, nums.size() - 1);
    return result;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    for (auto x : permute(nums))
    {
        for (auto v : x)
            cout << v << " ";
        cout << endl;
    }
}