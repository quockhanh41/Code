#include <iostream>
using namespace std;
bool isPalindrome(int x)
{
    int a = x;
    int res = 0;
    while (a != 0)
    {
        res = res * 10 + a % 10;
        a /= 10;
    }
    if (res == x)
        return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    cout << isPalindrome(n);
}