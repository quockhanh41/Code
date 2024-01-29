#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> adj[100];
bool visited[100];
int parent[100];
void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
bool DFS(int u)
{
    visited[u] = 1;
    for (auto x : adj[u])
    {
        parent[x] = u;
        if (!visited[x])
        {
            if (DFS(x))
                return 1;
        }
        else if (x != parent[u])
            return 1;
    }
    return 0;
}
bool chuTrinh()
{
    for (int i = 1; i <= m; i++)
    {
        if (!visited[i])
            if (DFS(i))
                return 1;
    }
    return 0;
}
int color[100];
bool DFS2(int u)
{
    color[u] = 1;
    for (auto x : adj[u])
        if (color[x] == 0)
        {
            if (DFS2(x))
                return 1;
        }
        else if (color[x] == 1)
            return 1;
    color[u] = 2;
    return 0;
}
bool chuTrinhCoHuong()
{
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            if (DFS2(i))
                return 1;
        }
    }
    return 0;
}
int main()
{
    inp();
    // cout << chuTrinhCoHuong();
    cout << chuTrinh();
    return 0;
}