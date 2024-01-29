#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
// {
//     sort(potions.begin(), potions.end());
//     vector<double> f;
//     vector<int> res;
//     int m = potions.size();
//     for (auto x : potions)
//         f.push_back((double)success / x);

//     for (auto x : spells)
//     {
//         int l = 0;
//         int r = m - 1;
//         if (x >= f[0])
//         {
//             res.push_back(m);
//             continue;
//         }
//         while (l <= r)
//         {
//             int mid = (l + r) / 2;
//             if (x >= f[mid] && x < f[mid - 1])
//             {
//                 res.push_back(m - mid);
//                 break;
//             }
//             else if (x < f[mid])
//                 l = mid + 1;
//             else
//                 r = mid - 1;
//             if (mid == m - 1)
//                 res.push_back(0);
//         }
//     }
//     return res;
// }
vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    sort(potions.begin(), potions.end());
    vector<int> ans;
    for (int i = 0; i < spells.size(); i++)
    {
        ios_base::sync_with_stdio(0);
        long long int spell = spells[i];
        long long int low = 0;
        long long int high = potions.size() - 1;
        while (low <= high)
        {
            long long int mid = (low + high) >> 1;
            if (potions[mid] * spell >= success)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        ans.push_back(potions.size() - low);
    }
    return ans;
}
int main()
{
    vector<int> spells = {15, 8, 19};
    vector<int> potions = {38, 36, 23};
    int success = 328;
    for (auto x : successfulPairs(spells, potions, success))
        cout << x << " ";
}
