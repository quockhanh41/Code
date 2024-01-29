#include <iostream>
#include <vector>
using namespace std;
int findCenter(vector<vector<int>> &edges)
{
    int x = edges[0][0];
    int y = edges[0][1];
    if (edges[1][0] == x || edges[1][1] == x)
        return x;
    return y;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}