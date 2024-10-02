#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    stack<int> s;
    int n = nums2.size();
    int *f = new int[10001];
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= nums2[i])
            s.pop();
        if (s.empty())
            f[nums2[i]] = -1;
        else
            f[nums2[i]] = s.top();
        s.push(nums2[i]);
    }
    for (auto x : nums1)
        res.push_back(f[x]);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {1, 3, 4, 2};
    nextGreaterElement(a, a);
    return 0;
}