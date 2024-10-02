#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
{
    vector<string> res;
    int index = INT_MAX;
    map<string, int> m;
    for (int i = 0; i < list1.size(); i++)
    {
        m[list1[i]] = i + 1;
    }
    for (int i = 0; i < list2.size(); i++)
    {
        cout << list2[i] << " " << m[list2[i]] + i << endl;
        if (m[list2[i]] + i > index || m[list2[i]] == 0)
            continue;
        if (m[list2[i]] + i < index)
        {
            index = m[list2[i]] + i;
            res.clear();
        }
        res.push_back(list2[i]);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> r1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> r2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};

    for (auto x : findRestaurant(r1, r2))
        cout << x;

    return 0;
}