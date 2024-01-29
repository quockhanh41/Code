#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
bool one = 1;
vector<int> nums;
int sum1 = 0;
int l = 0;
int r = nums.size() - 1;
bool PredictTheWinner(vector<int> &nums)
{
    if (l - r == 1)
    {
        // cout << sum1 << " " << (accumulate(nums.begin(), nums.end(), 0) - sum1);
        return sum1 >= (accumulate(nums.begin(), nums.end(), 0) - sum1);
    }
    if (one)
    {
        cout << sum1 << " " << nums[r] << " " << nums[l] << endl;
        if (nums[r] > nums[l])
            sum1 += nums[r--];
        else
            sum1 += nums[l++];
    }
    else
    {

        if (nums[r] > nums[l])
            r--;
        else
            l++;
    }
    one = !one;
    return PredictTheWinner(nums);
}
int main()
{
    int n;
    cin >> n;
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }

    cout << PredictTheWinner(nums);
}