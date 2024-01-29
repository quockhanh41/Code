#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;
int kConcatenationMaxSum(vector<int> &arr, int k)
{
    int n = arr.size();
    int sum = arr[0], mx = arr[0];
    int64_t total = accumulate(arr.begin(), arr.end(), 0), mod = 1e9 + 7;
    for (int i = 1; i < n * min(k, 2); i++)
    {
        sum = max(arr[i % n], sum + arr[i % n]);
        mx = max(mx, sum);
    }
    return max<int64_t>({0, mx, max(0, k - 2) * total + mx}) % mod;
}

int main()
{
    vector<int> a = {1, -3, 5};
    cout << kConcatenationMaxSum(a, 3);
}