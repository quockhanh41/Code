#include <iostream>
using namespace std;
int trailingZeroes(int n)
{
    if (n < 5)
        return 0;
    return n / 5 + trailingZeroes(n / 5);
}
