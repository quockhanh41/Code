#include <iostream>
#include <vector>
using namespace std;
int color[1001];
void DFS(int u, vector<vector<int>> &rooms)
{
    color[u] = 1;
    for (auto x : rooms[u])
    {
        if (color[x] == 0)
            DFS(x, rooms);
    }
    color[u] = 2;
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    DFS(0, rooms);
    for (int i = 0; i < rooms.size(); i++)
    {
        if (color[i] != 2)
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}