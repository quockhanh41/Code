#include <iostream>
#include <vector>

using namespace std;
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> res;
    int cnt[10000];
    for (auto x : nums)
    {
        cnt[x]++;
        if (cnt[x] == 2)
            res.push_back(x);
    }
    return res;
}
int main()
{
    vector<int> a = {4, 3, 2, 7, 8, 2, 3, 1};
    for (auto x : findDuplicates(a))
        cout << x << " ";
}