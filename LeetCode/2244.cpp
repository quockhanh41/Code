#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int minimumRounds(vector<int> &tasks)
{
    int res = 0;
    sort(tasks.begin(), tasks.end());
    set<int> s(tasks.begin(), tasks.end());
    vector<int> a(s.begin(), s.end());  
    int j = 0;
    int count = 0;
    for (int i = 0; i < tasks.size(); i++)
    {
        if (a[j] == tasks[i])
            count++;
        if (a[j] != tasks[i])
        {
            a[j] = count;
            j++;
            i--;
            count = 0;
        }
        if (i == tasks.size() - 1)
        {
            a[j] = count;
            j++;
        }
    }
    for (auto x : a)
    {
        if (x < 2)
            return -1;
        if (x % 3 == 0)
            res += x / 3;
        else
            res += x / 3 + 1;
    }
    return res;
}
int main()
{
    vector<int> a = {7, 7, 7, 7, 7, 7};
    cout << minimumRounds(a);
}