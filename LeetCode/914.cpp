#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
bool hasGroupsSizeX(vector<int> &deck)
{
    

    int cnt[10000] = {};
    for (auto x : deck)
        cnt[x]++;
    int min = cnt[deck[0]];
    for (int i = 1; i < deck.size(); i++)
    {
        if (cnt[deck[i]] < min)
            min = cnt[deck[i]];
    }
    if (min % 2 == 0)
    {
        for (auto x : deck)
            if (cnt[x] % 2 != 0)
                return false;
    }

    else

        for (auto x : deck)
            if (cnt[x] % min != 0)
                return false;

    return true;
}

int main()
{
    vector<int> a = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2};
    cout << hasGroupsSizeX(a);
}
