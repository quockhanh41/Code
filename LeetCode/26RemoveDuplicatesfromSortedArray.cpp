#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    vector<int> a;
    for (auto x : nums)
    {
        bool push = true;
        for (auto y : a)
        {
            if (x == y)
            {
                push = false;
                break;
            }
        }
        if (push)
            a.push_back(x);
    }
    nums = a;
    return a.size();
}
int main()
{
    vector<int> a = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(a) << endl;
    for (auto x : a)
        cout << x << " ";
    return 0;
}