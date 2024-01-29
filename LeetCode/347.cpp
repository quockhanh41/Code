#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> res;
    map<int, int> m;
    for (int x : nums)
        m[x]++;
    set<int> s(nums.begin(), nums.end());
    vector<int> v(s.begin(), s.end());
    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (m[v[j]] > m[v[i]])
                swap(v[i], v[j]);
        }
    }
    for (int i = 0; i < k; i++)
        res.push_back(v[i]);
    return res;
}
int main()
{
}