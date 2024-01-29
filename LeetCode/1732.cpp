#include <iostream>
#include <vector>
using namespace std;
int largestAltitude(vector<int> &gain)
{
    int res = 0;
    int sum = 0;
    for (int i = 0; i < gain.size(); i++)
    {
        sum += gain[i];
        res = max(res, sum);
    }
    return max(0, res);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}