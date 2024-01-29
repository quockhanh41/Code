#include <iostream>
#include <map>
#include <vector>
using namespace std;
string kthDistinct(vector<string> &arr, int k)
{
    map<string, int> m;
    for (auto x : arr)
        m[x]++;
    for (auto x : arr)
        if (m[x] == 1)
        {
            k--;
            if (k == 0)
                return x;
        }
    return "";
}
int main()
{
    vector<string> s = {"d", "b", "c", "b", "c", "a"};
    cout << kthDistinct(s, 2);
}