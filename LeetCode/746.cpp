#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> F(n);
    F[0] = cost[0];
    F[1] = cost[1];
    for (int i = 2; i < n; i++)
    {
        F[i] = min(F[i - 2] + cost[i], F[i - 1] + cost[i]);
    }
    return min(F[n - 1], F[n - 2]);
}
int main()
{
    vector<int> a = {10, 15, 20};
    cout << minCostClimbingStairs(a);
}