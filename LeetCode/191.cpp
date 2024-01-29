#include <iostream>
using namespace std;
int hammingWeight(uint32_t n)
{
    int cnt = 0;
    while (n)
    {
        cout << n << endl;
        if (n % 10 == 1)
            cnt++;
        n /= 10;
    }
    return cnt;
}
int main()
{
    cout << hammingWeight(00000000000000000000000000001011);
}