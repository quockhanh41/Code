#include <iostream>
using namespace std;
bool digitCount(string num)
{
    int cnt[10] = {0};
    for (int i = 0; i < num.size(); i++)
    {
        cnt[num[i] - '0']++;
    }
    for (int i = 0; i < num.size(); i++)
    {
        cout << i << " " << num[i] - '0' << " " << cnt[i] << endl;
        if (num[i] - '0' != cnt[i])
            return false;
    }
    return true;
}
int main()
{
    cout << digitCount("1210");
}