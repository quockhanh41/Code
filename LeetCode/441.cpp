#include <iostream>
using namespace std;
int arrangeCoins(int n)
{
    int i = 1;
    while (i <= n)
    {
        n -= i;
        i++;
    }
    return i - 1;
}
int main()
{
    cout << arrangeCoins(8);
    return 0;
}
