#include <iostream>
using namespace std;
long long reverse(long long x)
{
    if (x > INT_MAX || x < INT_MIN)
        return 0;
    long long res = 0;
    while (x != 0)
    {

        res = res * 10 + (x % 10);
        x /= 10;
    }
    if (res > INT_MAX || res < INT_MIN)
        return 0;
    return res;
}
int main()
{
    int n;
    cin >>
        n;
    cout << reverse(n);
}