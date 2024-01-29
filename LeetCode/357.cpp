#include <iostream>
#include <cmath>
using namespace std;
int countNumbersWithUniqueDigits(int n)
{
    int cache[9] = {0, 0, 9};
    if (cache[n])
        return pow(10, n) - cache[n];
    for (int i = 3; i <= n; i++)
    {
        cache[i] = cache[i - 1] * 10;
    }
    return pow(10, n) - cache[n];
}
int main()
{
    cout << countNumbersWithUniqueDigits(0);
    return 0;
}