#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
bool visited[100][100] = {0};
vector<int> adj[1001];
int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};
char a[101][101];
int path[100][100] = {-1};
int xa, ya, xb, yb;
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                xa = i;
                ya = j;
            }
            if (a[i][j] == 'B')
            {
                xb = i;
                yb = j;
                a[i][j] = 'o';
            }
        }
    }
}
void DFS(int i, int j)
{
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int xi = i + x[k];
        int xj = j + y[k];
        if (xi >= 1 && xi <= n && xj >= 1 && xj <= m && a[xi][xj] == 'o' && !visited[xi][xj])
            DFS(xi, xj);
    }
}

int demLienThong()
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 'o' && !visited[i][j])
            {
                count++;
                DFS(i, j);
            }
        }
    }
    return count;
}
bool isPath()
{
    DFS(xa, ya);
    return visited[xb][yb];
}

void BFS(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int xi = p.first + x[k];
            int xj = p.second + y[k];
            if (xi >= 1 && xi <= n && xj >= 1 && xj <= m && (a[xi][xj] == 'o' || a[xi][xj] == 'B') && !visited[xi][xj])
            {
                q.push({xi, xj});
                visited[xi][xj] = 1;
                path[xi][xj] = path[p.first][p.second] + 1;
            }
        }
    }
}
int minPath()
{
    BFS(xa, xa);
    return path[xb][yb];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    memset(path, 0, sizeof(path));
    //  cout << isPath();
    // cout << demLienThong();
    cout << minPath();
    return 0;
}