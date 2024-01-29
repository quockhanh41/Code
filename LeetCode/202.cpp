#include <iostream>
using namespace std;
int tongBinhPhuong(int n)
{
    int res = 0;
    while (n)
    {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}
bool isHappy(int n)
{
    int count = 0;
    if (tongBinhPhuong(n) == 1)
        return true;
    while (tongBinhPhuong(n) != 1 && count <= 100)
    {
        count++;
        n = tongBinhPhuong(n);
        if (tongBinhPhuong(n) == 1)
            return true;
    }
    return false;
}
int main()
{
    cout << isHappy(2);
    return 0;
}