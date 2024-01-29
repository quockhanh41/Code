#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]
vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
{
    vector<vector<int>> arr;
    vector<int> ans;
    for (int i = 0; i < restaurants.size(); i++)
    {
        arr.push_back({restaurants[i][1], restaurants[i][0], restaurants[i][2], restaurants[i][3], restaurants[i][4]});
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << arr[i][3] << " " << arr[i][4] << endl;
    }

    if (veganFriendly == 1)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i][2] == 1 && arr[i][3] <= maxPrice && arr[i][4] <= maxDistance)
                ans.push_back(arr[i][1]);
        }
    }
    else
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i][3] <= maxPrice && arr[i][4] <= maxDistance)
                ans.push_back(arr[i][1]);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<vector<int>> restaurants = {{1, 4, 1, 40, 10}, {2, 8, 0, 50, 5}, {3, 8, 1, 30, 4}, {4, 10, 0, 10, 3}, {5, 1, 1, 15, 1}};
    int veganFriendly = 0, maxPrice = 30, maxDistance = 3;
    for (auto x : filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance))
        cout << x << " ";
    return 0;
}