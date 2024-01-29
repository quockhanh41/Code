#include <iostream>
using namespace std;
double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    return x * myPow(x, n - 1);
}
int main()
{
    cout << myPow(2, 0);
    return 0;
}