#include <iostream>
#include <vector>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int maxi = 0;
    bool used[10000] = {0};
    for (auto x : nums)
    {
        used[x] = 1;
        maxi = max(maxi, x);
    }
    for (int i = 0; i <= maxi; i++)
        if (!used[i])
            return i;
    return 1;
}
int main()
{
  Ư=  cout << titleToNumber("AAA");
}