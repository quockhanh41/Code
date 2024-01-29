#include <iostream>
using namespace std;
bool isUgly(int n)
{
    while (n % 5 == 0 || n % 3 == 0 || n % 2 == 0)
    {
        if (n % 5 == 0)
            n /= 5;
        else if (n % 3 == 0)
            n /= 3;
        else
            n /= 2;
    }
    if (n == 1)
        return true;
    return false;
}
int main()
{
}