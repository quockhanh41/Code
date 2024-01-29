#include <iostream>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    string res = "";
    int index = 0;
    int n = strs.size();
    if (n == 1)
        return strs[0];
    while (index < strs[0].size())
    {
        for (int i = 1; i < n; i++)
        {
            if (strs[i][index] != strs[0][index])
                return res;
            if (i == n - 1)
                res += strs[0][index];
        }
        index++;
    }
    return res;
}
int main()
{
    vector<string> s = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(s);
    return 0;
}