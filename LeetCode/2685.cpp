#include <iostream>
#include <vector>
using namespace std;
bool visited[51] = {0};
vector<int> adj[51];
void DFS(int u, int &vertices, int &edges)
{
    vertices++;
    edges += adj[u].size();
    visited[u] = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            DFS(x, vertices, edges);
        }
    }
}
int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    int res = 0;
    for (auto x : edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int v = 0;
            int e = 0;
            DFS(i, v, e);
            res += (e / 2 == (v - 1) * v / 2);
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