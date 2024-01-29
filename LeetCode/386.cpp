#include <iostream>
#include <vector>
using namespace std;
vector<int> lexicalOrder(int n)
{
    vector<int> res;
    int i = 1;
    res.push_back(1);
    for (int j = 0; j < n - 1; j++)
    {
        if (10 * res[res.size() - 1] <= n)
            res.push_back(10 * res[res.size() - 1]);
        else if (res[res.size() - 1] + 1 <= n)
            res.push_back(res[res.size() - 1] + 1);
        else if (++i <= n)
            res.push_back(i);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (auto x : lexicalOrder(23))
        cout << x << " ";
    return 0;
}