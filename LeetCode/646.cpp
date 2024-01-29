#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> a, vector<int> b)
{
    return a[1] <= b[0];
}
int findLongestChain(vector<vector<int>> &pairs)
{
    int n = pairs.size();
    sort(pairs.begin(), pairs.end(), cmp);
    for (auto x : pairs)
        cout << x[0] << " " << x[1] << " ";
}
int main()
{
    vector<vector<int>> a = {{1, 2}, {2, 3}, {3, 4}};
    findLongestChain(a);
}