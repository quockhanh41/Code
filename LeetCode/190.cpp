#include <iostream>
#include <cmath>
using namespace std;
uint32_t reverseBits(uint32_t n)
{
    string s="";
    uint32_t res = 0;
    do
    {
        res += 
        n /= 10;
    } while (n);
    return res;
}
int main()
{
    cout << reverseBits(111);
}