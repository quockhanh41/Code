#include <iostream>
#include <vector>
using namespace std;
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    bool visited[1001] = {0};
    for (auto x : nums1)
        visited[x] = 1;
    for (auto x : nums2)
    {
        if (visited[x])
        {
            res.push_back(x);
            visited[x] = 0;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}