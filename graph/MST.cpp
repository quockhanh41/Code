#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> adj[1001];
int n, m;
struct Edge
{
    int s, e, w;
};
Edge e[1001];
int parent[1001];
int Size[1001];

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> e[i].s >> e[i].e >> e[i].w;
    sort(e, e + m, cmp);
}

void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        Size[i] = 1;
    }
}

int find(int x)
{
    if (x == parent[x])
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
        parent[b] = a;
        Size[a] += Size[b];
        return 1;
    }
    return 0;
}
void kruskal()
{
    int res = 0;
    makeSet(n);
    int i = 0;
    int d_MST = 0;
    while (d_MST < n && i < m)
    {
        if (Union(e[i].s, e[i].e) == 1)
        {
            res += e[i].w;
            cout << e[i].w << " ";
            d_MST++;
        }
        i++;
    }
    if (d_MST != n - 1)
        cout << "Do thi khong lien thong";
    else
        cout << "MST = " << res;
}

int prim()
{
    bool visited[1001];
    vector<int> adj2[1001];
    int a[100][100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0)
            {
                adj[i].push_back(j);
            }
        }
    vector<int> V;
    V.push_back(5);
    visited[5] = 1;
    while (V.size() < n)
    {
        int s, e;
        int min = INT_MAX;
        for (auto v : V)
        {
            for (auto x : adj[v])
            {
                if (!visited[x])
                {
                    if (a[v][x] < min)
                    {
                        s = v;
                        e = x;
                        min = a[v][x];
                    }
                }
            }
        }
        cout << s << " " << e << endl;
        adj2[s].push_back(e);
        adj2[e].push_back(s);
        V.push_back(e);
        visited[e] = 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (adj2[i].size() == 1)
            ans++;
    }

    // for (int i = 0; i < n; i++)
    //     cout << i << " " << adj2[i].size() << endl;
    // for (auto x : V)
    //     cout << x << " ";
    return ans;
}
int main()
{
    // cout << prim();

    input();
    kruskal();

    return 0;
}