#include <iostream>
#include <vector>
using namespace std;
int color[2001];
vector<int> adj[2001];
bool DFS(int u)
{
    color[u] = 1;
    for (auto x : adj[u])
    {
        if (color[x] == 1)
            return 0;
        else if (color[x] == 0)
        {
            if (!DFS(x))
                return 0;
        }
    }
    color[u] = 2;
    return 1;
}
// if exist cycle -> no topological oderting sort -> impossible
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    memset(color, 0, sizeof(color));
    for (auto x : prerequisites)
        adj[x[0]].push_back(x[1]);
    for (int i = 0; i <= numCourses; i++)
    {
        if (color[i] == 0)
        {
            if (!DFS(i))
                return 0;
        }
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}