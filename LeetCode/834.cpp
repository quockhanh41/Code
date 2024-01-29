#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[1001];
bool visited[1001];
int distance(int u)
{
    visited[u] = 1;
    if (adj[u].size() == 0)
        return 0;
    int dis = 0;
    for (auto x : adj[u])
    {
        if (!visited[x])
            dis += 1 + distance(x); 
    }
    return dis;
}
vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
{
    vector<int> res;
    for (auto x : edges)
    {
        adj[x[0]].push_back(x[1]);
    }
    for (int i = 0; i < n; i++)
    {
        res.push_back(distance(i));
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}