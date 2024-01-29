#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int rev(int n)
{
    int res = 0;
    while (n)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}
long long interchangeableRectangles(vector<vector<int>> &rectangles)
{
    int res = 0;
    map<double, int> m;
    for (auto x : rectangles)
        m[(double)x[0] / x[1]]++;
    for (auto i : m)
    {
        long long x = i.second;
        res += (x * (x - 1)) / 2.0;
    }
    return res;
}
int main()
{
    vector<vector<int>> a = {{1, 7}, {2, 8}, {8, 8}, {2, 5}, {2, 8}, {7, 4}};
    cout << interchangeableRectangles(a);
}
