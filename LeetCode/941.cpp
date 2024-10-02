#include <iostream>
#include <vector>
using namespace std;
bool validMountainArray(vector<int> &arr)
{
    if (arr.size() < 3)
        return false;
    bool trend = 1;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1] && trend == 1)
            trend = 0;
        if (arr[i] == arr[i + 1] || trend != arr[i] < arr[i + 1])
            return false;
    }
    if (trend == arr[0] < arr[1])
        return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}