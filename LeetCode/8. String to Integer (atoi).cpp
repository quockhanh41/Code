#include <iostream>
#include <string>
using namespace std;
int myAtoi(string s)
{
    int res = 0;
    bool am = 0;
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] >= '0' && s[i] <= '9')
        {

            res = res * 10 + s[i] - '0';
        }
        else if (s[i] == '-')
            am = 1;
    }
    if (am)
        res = -res;
    if (res < INT_MIN)
        return INT_MIN;
    if (res > INT_MAX)
        return INT_MAX;
    return res;
}
int main()
{
    string s;
    getline(cin, s);
    cout << myAtoi(s);
}
