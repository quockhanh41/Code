#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int parent[1001];
int Size[1001];

void makeSet(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        Size[i] = 1;
    }
}
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
    }
}
int main()
{
    makeSet(9);
    Union(4, 5);
    Union(3, 4);
    Union(2, 3);
    Union(1, 2);
    Union(1, 6);
    Union(6, 9);
    Union(1, 8);
    cout << find(5);
    return 0;
}