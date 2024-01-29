#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[1001];
bool visited[1001];
void DFS(int u)
{
    visited[u] = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
            DFS(x);
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int res = 0;
    for (int i = 0; i < isConnected.size(); i++)
    {
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[i][j])
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (!visited[i])
        {
            res++;
            DFS(i);
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