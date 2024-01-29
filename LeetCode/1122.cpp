#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> res;
    vector<int> res2;
    int cnt[1001] = {0};
    for (auto x : arr2)
        cnt[x]++;
    for (auto x : arr1)
    {
        if (cnt[x] == 0)
            res2.push_back(x);
        else
            cnt[x]++;
    }
    for (auto x : arr2)
    {
        for (int i = 0; i < cnt[x] - 1; i++)
        {
            res.push_back(x);
        }
    }
    sort(res2.begin(), res2.end());
    for (auto x : res2)
        res.push_back(x);
    return res;
}
int main()
{

    return 0;
}