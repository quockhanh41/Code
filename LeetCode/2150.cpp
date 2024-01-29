#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> findLonely(vector<int> &nums)
{
    vector<int> res;
    int m[1000001] = {0};
    for (auto x : nums)
        m[x]++;
    for (auto x : nums)
    {
        if (x == 0 && !m[x + 1] && m[x] == 1)
        {
            res.push_back(x);
            continue;
        }
        else if (!m[x - 1] && !m[x + 1] && m[x] == 1)
            res.push_back(x);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}