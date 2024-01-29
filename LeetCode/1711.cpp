#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

constexpr int MAX = (1 << 21) + 10;
constexpr int MOD = 1000000007;

int cnt[MAX];

int Add(int a, int b, int p = MOD)
{
    int c = a + b;
    return c < p ? c : c - p;
}

int countPairs(vector<int> &deliciousness)
{
    int ret = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int x : deliciousness)
    {
        for (int i = 0; i < 22; ++i)
        {
            int y = (1 << i) - x;
            if (y >= 0)
            {
                ret = Add(ret, cnt[y]);
            }
        }
        ++cnt[x];
    }
    return ret;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}