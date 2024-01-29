#include <iostream>
#include <vector>
using namespace std;
vector<int> res;
void DFS(int u, vector<vector<int>> &graph, vector<vector<int>> &ans)
{
    res.push_back(u);
    if (u == graph.size() - 1)
        ans.push_back(res);
    for (auto x : graph[u])
        DFS(x, graph, ans);
    res.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> ans;
    DFS(0, graph, ans);
    return ans;
}
int main()
{

    return 0;
}