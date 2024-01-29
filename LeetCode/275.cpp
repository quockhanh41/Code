#include <iostream>
#include <vector>
using namespace std;
int hIndex(vector<int> &citations)
{

    int res = 0;
    int l = 0;
    int r = citations.size() - 1;
    int n = citations.size();
    while (l <= r)
    {
        int m = (r + l) / 2;
        if (citations[m] >= n - m)
        {
            r = m - 1;
            res = max(res, n - m);
        }
        else
            l = m + 1;
    }
    return res;
}
int main()
{
    vector<int> a = {0, 1, 4, 5, 6, 7, 10};
    cout << hIndex(a);
    return 0;
}