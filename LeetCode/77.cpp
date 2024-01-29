#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
vector<int> v;
void backtrack(int n, int k, int index)
{
    if (v.size() == k)
    {
        res.push_back(v);
        return;
    }
    for (int i = index; i <= n; i++)
    {
        v.push_back(i);
        backtrack(n, k, i + 1);
        v.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    backtrack(n, k, 1);
    return res;
}
int main()
{

    for (auto x : combine(6, 4))
    {
        for (auto v : x)
            cout << v << " ";
        cout << endl;
    }
}