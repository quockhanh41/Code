#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> distinctDifferenceArray(vector<int> &nums)
{
    vector<int> f(nums.size());
    int count = 0;
    map<int, bool> used;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!used[nums[i]])
        {
            used[nums[i]] = 1;
            count++;
        }
        f[i] = count;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = 2 * f[i] - count;
    }
    return nums;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {3, 2, 3, 4, 2};

    for (auto x : distinctDifferenceArray(a))
        cout << x << " ";
    
    return 0;
}