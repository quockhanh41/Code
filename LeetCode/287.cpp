#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &nums)
{
    ios_base::sync_with_stdio(0);
    int n = nums.size();
    vector<bool> used(n);
    for (auto x : nums)
    {
        if (!used[x])
            used[x] = 1;
        else
            return x;
    }
    return 1;
}
int main()
{
}