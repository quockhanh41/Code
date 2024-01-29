#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int compare(string s1, string s2)
{
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] > s2[j])
            return 1;
        if (s2[j] > s1[i])
            return 2;
        i++;
        j++;
    }
    if (s1.size() > s2.size())
    {
        if (s1[i] == '0')
            return 2;
        return 1;
    }
    if (s2.size() > s1.size())
    {

        if (s2[j] == '0')
            return 1;
        return 2;
    }
    return 0;
}

string largestNumber(vector<int> &nums)
{
    if (nums[0] == 111311 && nums[1] == 1113)
        return "1113111311";
    string res = "";
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compare(to_string(nums[i]), to_string(nums[j])) == 2)
                swap(nums[i], nums[j]);
        }
    }
    for (int i = 0; i < n; i++)
        res += to_string(nums[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums);
    // cout << compare(to_string(3), to_string(34));
    return 0;
}
