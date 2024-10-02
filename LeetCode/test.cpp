#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> shuffle(vector<int> &nums, int n)
{
    int mid = nums.size() / 2;
    vector<int> res;
    for (int i = 0; i < mid; i++)
    {
        res.push_back(nums[i]);
        res.push_back(nums[i + mid]);
    }
    return res;
}
int main()
{
    string a = "khabh";
    cout << a.substr(0,3);

    return 0;
}