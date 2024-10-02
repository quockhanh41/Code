#include <iostream>
#include <vector>
using namespace std;
void sortColors(vector<int> &nums)
{
    int cnt[3] = {0};
    for (int i = 0; i < nums.size(); i++)
    {
        cnt[nums[i]]++;
    }
    int i = 0;
    while (cnt[0]--)
    {
        nums[i++] = 0;
    }
    while (cnt[1]--)
    {
        nums[i++] = 1;
    }
    while (cnt[2]--)
    {
        nums[i++] = 2;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}