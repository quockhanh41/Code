#include <iostream>
#include <vector>

using namespace std;
int sumOfUnique(vector<int> &nums)
{
    int n = nums.size();
    int cnt[101]={0};
    for (auto x : nums)
        cnt[x]++;
    int res = 0;
    for (auto x : nums)
        if (cnt[x] == 1)
            res += x;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}