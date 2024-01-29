#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool visited[1001];
vector<int> adj[100];
vector<int> topo;
int in[100];
int n, m;
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
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
void kahn()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (auto x : adj[u])
        {
            in[x]--;
            if (in[x] == 0)
                q.push(x);
        }
    }
    for (auto x : topo)
        cout << x << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //         DFS(i);
    // }
    // reverse(topo.begin(), topo.end());
    kahn();

    return 0;
}