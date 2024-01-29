#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int numberZeros(int n)
{
    if (n / 5 == 0)
        return 0;
    else
        return (n / 5) + numberZeros(n / 5);
}
int preimageSizeFZF(int k)
{
    int count = 0;
    for (int i = 0; i < (k + 1) * 5; i++)
    {
        if (numberZeros(i) == k)
            count++;
    }
    return count;
}
int main()
{
    cout << preimageSizeFZF(3);
}