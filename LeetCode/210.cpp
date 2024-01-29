#include <iostream>
#include <vector>
using namespace std;
int color[2001];
vector<int> adj[2001];
vector<int> topo;
bool DFS(int u)
{
    color[u] = 1;
    for (auto x : adj[u])
    {
        if (color[x] == 0)
        {
            if (!DFS(x))
                return 0;
        }
        else if (color[x] == 1)
            return 0;
    }
    color[u] = 2;
    topo.push_back(u);
    return 1;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    for (auto x : prerequisites)
        adj[x[0]].push_back(x[1]);
    memset(color, 0, sizeof(color));
    for (int i = 0; i < numCourses; i++)
    {
        if (color[i] == 0)
            if (!DFS(i))
            {
                topo.clear();
                return topo;
            }
    }
    return topo;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}