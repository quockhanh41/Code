#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[200001] ;
bool visited[200001] = {0};
void DFS(int u)
{
    visited[u] = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
            DFS(x);
    }
}
bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    for (auto x : edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    DFS(source);
    return visited[destination];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}