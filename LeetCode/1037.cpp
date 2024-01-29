#include <iostream>
#include <vector>
using namespace std;
bool isBoomerang(vector<vector<int>> &points)
{
    int vec[2][2];
    vec[0][0] = points[0][0] - points[1][0];
    vec[0][1] = points[0][1] - points[1][1];

    vec[1][0] = points[2][0] - points[1][0];
    vec[1][1] = points[2][1] - points[1][1];
    return (vec[0][0] * vec[1][1] == vec[1][0] * vec[0][1]);
}

int largestSum(int a[], int n)
{
    int sum = 0;
    int record = a[0];
    for (int i = 0; i < n; i++)
    {
        if (sum < 0)
            sum = 0;
        sum += a[i];
        record = max(record, sum);
    }
    return record;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[] = {-2, 11, -4, 13, -5, -2};
    int n = sizeof(a) / 4;
    cout << largestSum(a, n);
    return 0;
}