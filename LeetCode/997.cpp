#include <iostream>
#include <vector>

using namespace std;
int findJudge(int n, vector<vector<int>> &trust)
{
    int trusts[1001];
    int beTrusted[1001];
    
    for (auto x : trust)
    {
        trusts[x[0]]++;
        beTrusted[x[1]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (trusts[i] == 0 && beTrusted[i] == n - 1)
            return i;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}