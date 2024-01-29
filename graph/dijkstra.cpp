#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int d[100];
bool visited[1001] = {0};
vector<int> adj[1001];
int len[100][100];
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        d[i] = INT_MAX;
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(y);
        len[x][y] = z;
        
        adj[y].push_back(x);
        len[y][x] = z;
    }
}

int current()
{
    int index;
    int res = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && d[i] < res)
        {
            res = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra()
{
    d[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = current();
        visited[u] = 1;
        for (auto v : adj[u])
            d[v] = min(d[v], d[u] + len[u][v]);
    }
}
int main()
{
    input();
    dijkstra();
    for (int i = 1; i <= n; i++)
        cout << "d(" << i << ")= " << d[i] << endl;

    return 0;
}