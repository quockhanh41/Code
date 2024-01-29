#include <iostream>
using namespace std;
int cache[10000] = {0, 1, 1};
int tribonacci(int n)
{
    if (cache[n])
        return cache[n];
    for (int i = 3; i <= n; i++)
    {
        cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
    }
    return cache[n];
}

int dpFib(int n, int cache[])
{
    if (cache[n])
        return cache[n];
    cache[n] = dpFib(n - 1, cache) + dpFib(n - 2, cache) + dpFib(n - 3, cache);
    return cache[n];
}
int main()
{
    cout << dpFib(4,cache);
    return 0;
}