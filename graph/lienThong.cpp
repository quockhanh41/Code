#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
vector<int> adj[100];
vector<int> adj2[100];
bool visited[100];
vector<int> topo;
void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj2[y].push_back(x);
    }
}

void DFS(int u)
{
    visited[u] = 1;
    for (auto x : adj[u])
    {
        if (!visited[x])
            DFS(x);
    }
    topo.push_back(u);
}
void DFS2(int u)
{
    cout << u << " ";
    visited[u] = 1;
    for (auto x : adj2[u])
        if (!visited[x])
            DFS2(x);
}
void lienThong()
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            DFS(i);
    }
    reverse(topo.begin(), topo.end());
    memset(visited, 0, sizeof(visited));
    for (auto x : topo)
    {
        if (!visited[x])
        {
            cout << endl;
            DFS2(x);
        }
    }
}
int main()
{
    inp();
    lienThong();
    return 0;
}