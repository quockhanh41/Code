#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<vector<int>> s;
void backtrack(vector<int> &candidates, int index, int sum, int target, vector<int> a)
{
    if (index == candidates.size() || sum > target)
        return;
    if (sum == target)
    {
        sort(a.begin(), a.end());
        s.insert(a);
        return;
    }
    a.push_back(candidates[index]);
    backtrack(candidates, index + 1, sum + candidates[index], target, a);
    a.pop_back();
    backtrack(candidates, index + 1, sum, target, a);
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> a;
    backtrack(candidates, 0, 0, target, a);
    vector<vector<int>> res(s.begin(), s.end());
    return res;
}
int main()
{
    vector<int> a = {10, 1, 2, 7, 6, 1, 5};
    for (auto x : combinationSum2(a, 8))
    {
        for (auto y : x)
            cout << y;
        cout << endl;
    }
}
