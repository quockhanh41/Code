#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minStoneSum(vector<int> &piles, int k)
{
    while (k--)
    {
        sort(piles.begin(), piles.end());
        piles.back() -= piles.back() / 2;
    }
    int sum = 0;
    for (auto x : piles)
        sum += x;
    return sum;
}
int main()
{
    vector<int> a = {4,3,6,7};
    cout << minStoneSum(a, 3);
}
