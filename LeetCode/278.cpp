#include <iostream>
using namespace std;
bool isBadVersion(int version)
{
}
int firstBadVersion(int n)
{
    if (isBadVersion(1))
        return 1;
    int l = 1;
    int r = n;
    while (l <= r)
    {
        int mid = l / 2 + r / 2;
        if (isBadVersion(mid) == 0 && isBadVersion(mid + 1) == 1)
            return mid + 1;
        else if (isBadVersion(mid) == 0 && isBadVersion(mid + 1) == 0)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return 0;
}
int main()
{
}