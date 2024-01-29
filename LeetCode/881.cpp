#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int cnt = 0;
    int l = 0;
    int r = people.size() - 1;
    while (l <= r)
    {
        int sum = people[l] + people[r];
        if (sum <= limit)
            l++;
        r--;
        cnt++;
    }
    return cnt;
}

int main()
{
    vector<int> p = {3, 5, 3, 4, 1, 1, 2, 3, 2, 2, 1};
    cout << numRescueBoats(p, 5);
}