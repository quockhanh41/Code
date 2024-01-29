#include <iostream>
#include <vector>
using namespace std;

int minReorder(int n, vector<vector<int>> &connections)
{
    int res = 0;
    int capital[50001] = {0};
    capital[0] = 1;
    if (connections[0][1] == 0 || connections[0][0] == 0)
    {
        for (auto x : connections)
        {
            if (capital[x[0]])
            {
                res++;
                capital[x[1]] = 1;
            }
            else
            {
                capital[x[0]] = 1;
            }
        }
    }
    else
    {
        for (int i = connections.size() - 1; i >= 0; i--)
        {
            if (capital[connections[i][0]])
            {
                res++;
                capital[connections[i][1]] = 1;
            }
            else
            {
                capital[connections[i][0]] = 1;
            }
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}