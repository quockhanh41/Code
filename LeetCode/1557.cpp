#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int color[10001] = {0};
vector<int> adj[10001];
void DFS(int u)
{
    color[u] = 1;
    for (auto x : adj[u])
    {
        if (color[x] == 0)
            DFS(x);
    }
    color[u] = 2;
}
static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    vector<int> res;
    int degree[10001] = {0};

    for (auto x : edges)
    {
        degree[x[1]]++;
        adj[x[0]].push_back(x[1]);
    }

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++)
        arr.push_back({i, degree[i]});

    sort(arr.begin(), arr.end(), cmp);

    for (auto x : arr)
    {
        if (color[x.first] == 0)
        {
            DFS(x.first);
            res.push_back(x.first);
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    for (auto x : findSmallestSetOfVertices(6, edges))
        cout << x << " ";
    return 0;
}