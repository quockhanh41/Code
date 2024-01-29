#include <iostream>
#include <list>
#include <vector>

using namespace std;
void moveZeroes(vector<int> &nums)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i])
        {
            cout << i << " " << j << endl;
            swap(nums[j++], nums[i]);
        }
}
int main()
{
    vector<int> a = {0, 1, 0, 3, 12};
    moveZeroes(a);
    for (auto x : a)
        cout << x << " ";
    return 0;
}