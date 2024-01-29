#include <iostream>
#include <vector>
using namespace std;
int degree[1001];
bool visited[1001];
int n, m;
vector<int> adj[1001];
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }
}
void DFS(int u)
{
    visited[u] = 1;
    for (auto x : adj[u])
        if (!visited[x])
            DFS(x);
}
// tất cả các đỉnh có bậc khác 0 phải liên thông với nhau
// tất cả các đỉnh đều phải là bậc chẵn 
bool EulerCycle()
{
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] % 2 != 0)
            return 0;
        if (!visited[i] && degree[i] != 0 && k == 0)
        {
            DFS(i);
            k++;
        }
        else if (!visited[i])
            return 0;
    }
    return 1;
}
// tất cả các đỉnh có bậc khác 0 phải liên thông với nhau
// có 0 hoặc 2 đỉnh có bậc lẻ, nếu có 2 đỉnh bậc lẻ thì đường đi sẽ là từ đỉnh này đến đỉnh còn lại
bool EulerPath()
{
    int countOddDegree = 0;
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] & 1)
            countOddDegree++;

        if (!visited[i] && degree[i] != 0 && k == 0)
        {
            DFS(i);
            k++;
        }
        else if (!visited[i])
            return 0;
    }
    if (countOddDegree != 0 && countOddDegree != 2)
        return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    // cout << EulerCycle();
    cout << EulerPath();
    return 0;
}