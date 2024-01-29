#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res(numRows);
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0)
            {
                res[i].push_back(1);
            }
            else
            {
                res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
        }
    }
    return res;
}
int main()
{
    for (auto x : generate(5))
    {
        for (auto v : x)
            cout << v << " ";
        cout << endl;
    }

    return 0;
}