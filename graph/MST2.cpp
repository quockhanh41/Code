#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1001];
int Size[1001];
int n, m;
struct Edge
{
    int s, e, w;
};
Edge a[1001];
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i].s >> a[i].e >> a[i].w;
    sort(a, a + m, cmp);
}

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

bool Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);
        Size[a] += Size[b];
        parent[b] = a;
        return 1;
    }
    return 0;
}
void kruskal()
{
    makeSet(n);
    int res = 0;
    int d_MST = 0;
    int i = 0;
    while (d_MST < n && i < m)
    {
        if (Union(a[i].s, a[i].e) == 1)
        {
            res += a[i].w;
            d_MST++;
        }
        i++;
    }
    if (d_MST != n - 1)
        cout << "khong lien thong";
    else
        cout << "MST = " << res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    kruskal();
    return 0;
}