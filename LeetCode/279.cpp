#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int numSquares(int n)
{
    if (sqrt(n) == (int)sqrt(n))
        return 1;
    int *f = new int[n + 1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = INT_MAX;
    }

    for (int i = n; i >= 1; i--)
    {
        if (sqrt(i) == (int)sqrt(i))
        {
            for (int j = i; j <= n; j++)
            {
                if (f[j - i] != INT_MAX)
                    f[j] = min(f[j], f[j - i] + 1);
            }
        }
    }

    return f[n];
}
int main()
{
    cout << numSquares(4);
}