#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[1001];
bool visited[1001];
vector<int> topo;
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

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
{
    vector<bool> res;
    if (prerequisites.empty())
    {
        for (auto x : queries)
        {
            res.push_back(false);
        }
        return res;
    }
    int *index = new int[numCourses];
    for (auto x : prerequisites)
    {
        adj[x[0]].push_back(x[1]);
    }
    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
    reverse(topo.begin(), topo.end());

    for (int i = 0; i < topo.size(); i++)
    {
        cout << topo[i] << " " ;
        index[topo[i]] = i;
    }
    for (auto x : queries)
    {
        if (index[x[0]] < index[x[1]])
            res.push_back(true);
        else
            res.push_back(false);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}