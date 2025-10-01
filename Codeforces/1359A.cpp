/**
 * @file 1359A.cpp
 * @author quckhanh41
 * @date 2025-09-27 21:29
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    int count[101] = {0};
    set<int> s;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
        count[x]++;
    }
    if (s.size() == 2 && count[*s.begin()] == count[*(++s.begin())])
    {
        cout << "YES\n";
        cout << *s.begin() << " " << *(++s.begin());
    }
    else
    {
        cout << "NO";
    }

    return 0;
}