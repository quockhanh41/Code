#include <iostream>
#include <vector>
using namespace std;
int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0, j = arr1.size() - 1;
    int res = abs(arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) + abs(i - j);
    while (i < j )
    {
        res = max(res, abs(arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) + abs(i - j));
        cout << i << " " << j << " " << res << endl;
        if (abs(arr1[i + 1] - arr1[j]) + abs(arr2[i + 1] - arr2[j]) >= abs(arr1[i] - arr1[j - 1]) + abs(arr2[i] - arr2[j - 1]))
            i++;
        else
            j--;
    }
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr1.size(); j++)
        {
            res = max(res, abs(arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) + abs(i - j));
            cout << i << " " << j << " " << res << endl;
        }
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {0, 7, 5, -3, 8, 3, 5, 4};
    vector<int> b = {-5, 8, 5, 3, 0, 1, -5, 0};
    cout << maxAbsValExpr(a, b);

    return 0;
}