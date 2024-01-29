#include <iostream>
#include <vector>
using namespace std;
// int maxArea(vector<int> &height)
// {
//     int max = min(height[0], height[1]);
//     for (int i = 0; i < height.size(); i++)
//     {
//         for (int j = i + 1; j < height.size(); j++)
//         {
//             if (min(height[i], height[j]) * (j - i) > max)
//                 max = min(height[i], height[j]) * (j - i);
//         }
//     }
//     return max;
// }
int maxArea(vector<int> &height)
{
    int l = 0;
    int r = height.size() - 1;
    int s = height.size() - 1;
    int max = min(height[l], height[r]) * s;

    while (s != 0)
    {
        if (height[l] < height[r])
            l++;
        else
            r--;
        s--;
        if (min(height[l], height[r]) * s > max)
            max = min(height[l], height[r]) * s;
    }
    return max;
}

int main()
{
    vector<int> a = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(a);
    return 0;
}
