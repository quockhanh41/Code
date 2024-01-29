#include <iostream>
#include <vector>
#include <map>
using namespace std;
int singleNumber(vector<int> &nums)
{
    map<int, int> cnt;
    for (auto x : nums)
        cnt[x]++;
    for (auto x : nums)
        if (cnt[x] == 1)
            return x;
    return -1;
}
int main()
{
}