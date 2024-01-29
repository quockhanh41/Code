#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int> &nums, int val)
{

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == val)
        {
            swap(nums[i], nums[nums.size() - 1]);
            nums.pop_back();

            i--;
        }
    }
    return nums.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << removeElement(a, 2) << endl;
    for (auto x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}