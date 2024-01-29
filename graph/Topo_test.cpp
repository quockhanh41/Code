#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
vector<int> adj[1001];
int color[1001];
vector<int> topo;
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
}
void DFS(int u)
{
    color[u] = 1;
    for (auto x : adj[u])
    {
        if (color[x] == 0)
        {
            DFS(x);
        }
    }
    color[u] = 2;
    topo.push_back(u);
}
void printTopoOder()
{
    memset(color, 0, sizeof(color));
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
            DFS(i);
    }
    reverse(topo.begin(), topo.end());
    for (auto x : topo)
        cout << x << " ";
}
int main()
{
    input();
    printTopoOder();
    return 0;
}