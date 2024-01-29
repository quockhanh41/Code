#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> a;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        a.push_back(nums[i]);
                        a.push_back(nums[j]);
                        a.push_back(nums[k]);
                        sort(a.begin(), a.end());
                        bool push = true;
                        for (auto x : res)
                            if (a == x)
                            {
                                push = false;
                                break;
                            }
                        if (push)
                            res.push_back(a);
                        a.pop_back();
                        a.pop_back();
                        a.pop_back();
                    }
                }
            }
        }
        return res;
    }

int main()
{
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    auto res = threeSum(a);
    // cout << res[0].size();
    for (int i = 0; i < threeSum(a).size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
    }

    return 0;
}