#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    ios::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    vector<int> arr;
    int n = matrix[0].size();
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr.push_back(matrix[i][j]);
        }
    }
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}
int main()
{
    int k = 8;
    vector<vector<int>> a = {{1, 5, 9}, {12, 13, 15}, {12, 13, 15}};
    cout << kthSmallest(a, k);
}