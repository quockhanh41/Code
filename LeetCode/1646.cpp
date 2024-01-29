#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int getMaximumGenerated(int n)
{
    vector<int> cache(n);
    cache[0] = 0;
    cache[1] = 1;
    for (int i = 1; 2 * i + 1 <= n; i++)
    {
        cache[2 * i] = cache[i];
        cache[2 * i + 1] = cache[i] + cache[i + 1];
    }
    return *max_element(cache.begin(), cache.end());
}
int main()
{
    cout << getMaximumGenerated(7);
    return 0;
}
