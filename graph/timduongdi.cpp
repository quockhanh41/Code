#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[1001];
int n, m;
char a[100][100];
bool visited[1001][1001] = {0};

void DFS(int i, int j)
{
    visited[i][j] = 1;
    if ((a[i][j + 1] == 'x' || a[i][j + 1] == 'B') && j + 1 < m && !visited[i][j + 1])
        DFS(i, j + 1);
    if ((a[i + 1][j] == 'x' || a[i + 1][j] == 'B') && i + 1 < n && !visited[i + 1][j])
        DFS(i + 1, j);
    if ((a[i][j - 1] == 'x' || a[i][j - 1] == 'B') && j - 1 >= 0 && !visited[i][j - 1])
        DFS(i, j - 1);
    if ((a[i - 1][j] == 'x' || a[i - 1][j] == 'B') && i - 1 >= 0 && !visited[i - 1][j])
        DFS(i - 1, j);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    DFS(1, 1);
    cout << visited[4][4];
    return 0;
}