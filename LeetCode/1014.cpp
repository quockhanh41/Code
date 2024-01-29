#include <iostream>
#include <vector>
using namespace std;
int maxScoreSightseeingPair(vector<int> &values)
{
    int res = values[0] + values[1] - 1;
    int maxi = values[0];
    for (int i = 1; i < values.size() - 1; i++)
    {
        maxi = max(maxi, values[i] + i);
        res = max(res, maxi + values[i + 1] - i - 1);
    }
    return res;
}
int main()
{
    vector<int> a = {7, 8, 8, 10};
    cout << maxScoreSightseeingPair(a);
    return 0;
}