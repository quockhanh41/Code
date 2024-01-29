#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool visited[1001] = {0};
int parent[1001] = {0};
vector<int> adj[1001];

void DFS(int u)
{
    // cout << u << " ";
    visited[u] = 1;
    for (auto x : adj[u])
        if (!visited[x])
        {
            DFS(x);
            parent[x] = u;
        }
}
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        // cout << v << " ";
        for (auto x : adj[v])
            if (!visited[x])
            {
                q.push(x);
                visited[x] = 1;
            }
    }
}
int demLienThong(int n)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            res++;
            DFS(i);
        }
    }
    return res;
}
void duongDi(int a, int b)
{
    vector<int> path;
    path.push_back(b);
    DFS(a);
    if (visited[b])
    {
        while (b != a)
        {
            path.push_back(parent[b]);
            b = parent[b];
        }
        reverse(path.begin(), path.end());
        for (auto x : path)
            cout << x << " ";
    }
    else
        cout << "no path";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    duongDi(5, 9);
    return 0;
}