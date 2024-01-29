#include <iostream>
#include <vector>
using namespace std;
int countPrimes(int n)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (n < 2)
        return 0;
    int res = 0;
    bool used[5000000] = {0};
    for (int i = 2; i < n; i++)
        if (!used[i])
        {
            for (int j = i * 2; j < n; j += i)
                used[j] = 1;
            res++;
        }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << countPrimes(10);
    return 0;
}