#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
int rev(int n)
{
    int res = 0;
    while (n)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}
int countNicePairs(vector<int> &nums)
{
    int res = 0;

    map<int, int> m;
    for (auto x : nums)
        m[x - rev(x)]++;
    for (auto i : m)
    {
        int x = i.second;
        res += (x * (x - 1)) / 2;
    }
    return res;
}
int main()
{
    vector<int> a = {13, 10, 35, 24, 76};
    cout << countNicePairs(a);
}