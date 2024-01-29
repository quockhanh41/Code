#include <iostream>
using namespace std;
int divide(int dividend, int divisor)
{
    long long a = dividend;
    long long b = divisor;
    if (dividend > INT_MAX * divisor)
        return INT_MAX;
    if (dividend < INT_MIN * divisor)
        return INT_MIN;
    return dividend / divisor;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << divide(a, b);
    return 0;
}