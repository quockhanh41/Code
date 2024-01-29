#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findRadius(vector<int> &houses, vector<int> &heaters)
{
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    int res = 0;
    int j = 0;
    int i = 0;
    while (i < houses.size())
    {
        if (houses[i] <= heaters[j])
        {
            // cout << heaters[j] - houses[i] << " ";
            res = max(res, heaters[j] - houses[i]);
            i++;
        }
        else if (j + 1 <= heaters.size() - 1 && houses[i] > heaters[j + 1])
            j++;
        else if (j == heaters.size() - 1)
        {
            // cout << houses[i] - heaters[j] << " ";
            res = max(res, houses[i] - heaters[j]);
            i++;
        }
        else if (j + 1 <= heaters.size() - 1)
        {
            // cout << min(houses[i] - heaters[j], heaters[j + 1] - houses[i]) << " ";
            res = max(res, min(houses[i] - heaters[j], heaters[j + 1] - houses[i]));
            i++;
        }
    }
    return res;
}
int main()
{
    vector<int> a = {282475249, 622650073, 984943658, 144108930, 470211272, 101027544, 457850878, 458777923};
    vector<int> b = {823564440, 115438165, 784484492, 74243042, 114807987, 137522503, 441282327, 16531729, 823378840, 143542612};
    cout << findRadius(a, b);
    return 0;
}
