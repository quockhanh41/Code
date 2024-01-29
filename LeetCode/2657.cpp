#include <iostream>
#include <vector>
using namespace std;
vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
    int k = 0;
    vector<int> res;
    int n = A.size();
    bool exist1[51] = {0};
    bool exist2[51] = {0};
    for (int i = 0; i < n; i++)
    {
        if (A[i] != B[i])
            k += (exist1[A[i]] + exist2[B[i]]);
        else
            k++;
        res.push_back(k);
        exist1[A[i]] = exist2[B[i]] = 1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}