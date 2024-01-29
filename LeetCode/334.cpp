#include <iostream>
#include <vector>
using namespace std;
bool increasingTriplet(vector<int> &nums)
{
    ios_base::sync_with_stdio(false);
    int n = nums.size();
    vector<int> min_left(n);
    min_left[0] = nums[0];
    for (int i = 1; i < n; i++)
        min_left[i] = min(min_left[i - 1], nums[i]);
    vector<int> max_right(n);
    max_right[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
        max_right[i] = max(max_right[i + 1], nums[i]);
    for (int i = 1; i < n - 1; i++)
    {
        if (min_left[i - 1] < nums[i] && nums[i] < max_right[i + 1])
            return true;
    }
    return false;
}
int main()
{
}