#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int res = 0;
const int MAX = 1e5 + 1;
int parent[MAX];
int Size[MAX];
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
        res = max(Size[a], res);
    }
}
int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    bool visited[MAX];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        visited[nums[i]] = 1;
        parent[nums[i]] = nums[i];
        Size[nums[i]] = 1;
        if (visited[nums[i] - 1])
            Union(nums[i], nums[i] - 1);
        if (visited[nums[i] + 1])
            Union(nums[i], nums[i] + 1);
    }
    return res;
}
int main()
{
    vector<int> a = {0};
    cout << longestConsecutive(a);

    return 0;
}