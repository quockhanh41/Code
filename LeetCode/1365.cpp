#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// vector<int> smallerNumbersThanCurrent(vector<int> &nums)
// {
//     int m = 0;
//     int cnt[101] = {0};
//     int res[101];
//     for (auto x : nums)
//     {
//         cnt[x]++;
//         m = max(m, x);
//     }
//     res[0] = 0;
//     for (int i = 1; i <= m; i++)
//     {
//         res[i] = res[i - 1] + cnt[i - 1];
//         // cout << res[i] << " " << res[i - 1] << " " << cnt[i - 1] << endl;
//     }
//     for (int i = 0; i < nums.size(); i++)
//     {
//         // cout << cnt[nums[i]] << " ";
//         nums[i] = res[nums[i]];
//     }
//     return nums;
// }
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<pair<int, int>> v;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end(), cmp);
    int arr[101] = {0};
    for (int i = 0; i < nums.size(); i++)
    {
        arr[v[i].first]++;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " ";
    }
    cout << endl;
    int n=nums.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[v[i].first] == 1)
        {
            res.push_back(nums.size() - arr[v[i].first]);
            nums.pop_back();
        }else {
            int n=nums.size();
            for(int j=0;j<arr[v[i].first];j++){
                int a=n - arr[v[i].first];
                res.push_back(a);
                nums.pop_back();
            }
            i-=arr[v[i].first]-1;
        }
    }
    
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {8,1,2,2,3};
    for (auto x : smallerNumbersThanCurrent(a))
        cout << x << " ";
    // smallerNumbersThanCurrent(a);
    return 0;
}