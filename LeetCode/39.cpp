#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
void backtrack(vector<int> &candidates, int target, int index, int sum, vector<int> arr)
{
    if (sum == target)
    {
        res.push_back(arr);
        return;
    }
    if (sum > target || index >= candidates.size())
    {
        return;
    }
    arr.push_back(candidates[index]);
    backtrack(candidates, target, index, sum + candidates[index], arr);
    arr.pop_back();
    backtrack(candidates, target, index + 1, sum, arr);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> arr;
    backtrack(candidates, target, 0, 0, arr);
    return res;
}
int main()
{
    vector<int> a = {2, 3, 6, 7};
    for (auto x : combinationSum(a, 7))
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}