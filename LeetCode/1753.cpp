#include <iostream>
using namespace std;
int maximumScore(int a, int b, int c)
{
    int res = 0;
    if (a > b)
        return maximumScore(b, a, c);
    if (b > c)
        return maximumScore(a, c, b);
    if (a == 0 && b == 0)
        return 0;
    if (a == b)
        return a + c / 2;
    if (b == c)
    {
        if (a > 1)
            return a + (b - a / 2);
        else
            return b;
    }
    int dis = c - b;
    
    return res;
}
int main()
{
    cout << maximumScore(6, 7, 12);
    return 0;
}