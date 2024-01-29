#include <iostream>
#include <vector>
using namespace std;
string largestGoodInteger(string num)
{
    string s = "   ";
    int n = num.size();
    string res = "   ";
    for (int i = 0; i < n - 2; i++)
    {
        if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
        {
            s[0] = num[i];
            s[1] = num[i];
            s[2] = num[i];
        }
        if (res == "   " || s[0] > res[0])
            res = s;
    }
    if (res == "   ")
        return "";
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << largestGoodInteger("2300019");
    return 0;
}