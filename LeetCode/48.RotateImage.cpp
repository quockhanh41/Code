#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<vector<int>> &matrix)
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
    matrix = res;
}
