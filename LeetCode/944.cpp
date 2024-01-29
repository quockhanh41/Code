#include <iostream>
#include <vector>
using namespace std;
int minDeletionSize(vector<string> &strs)
{
    int count = 0;
    int n = strs[0].size();
    int i = 0;
    int m = strs.size() - 1;
    while (i < n)
    {
        for (int j = 0; j < m; j++)
        {
            if (strs[j][i] > strs[j + 1][i])
            {
                count++;
                break;
            }
        }
        i++;
    }
    return count;
}
int main()
{
    vector<string> a = {"cba", "daf", "ghi"};
    cout << minDeletionSize(a);
}