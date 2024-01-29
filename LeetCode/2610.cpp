#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> findMatrix(vector<int> &nums)
{
    vector<vector<int>> res;
    int n = nums.size();
    vector<vector<int>> group(201);
    bool exist[201][201] = {0}; // [group jth][key]
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (exist[j][nums[i]])
            j++;
        group[j].push_back(nums[i]);
        exist[j][nums[i]] = 1;
    }
    for (auto x : group)
        if (!x.empty())
            res.push_back(x);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}