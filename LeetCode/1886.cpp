#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> rotate(vector<vector<int>> &matrix)
{
    vector<vector<int>> res = matrix;
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[j][n - 1 - i] = matrix[i][j];
        }
    }
    return res;
}
bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
{
    int t = 5;
    for (int i = 0; i < 4; i++)
    {
        mat = rotate(mat);
        if (rotate(mat) == target)
            return true;
    }

    return false;
}
int main()
{
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> target = {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    cout << findRotation(mat, target);
    return 0;
}
