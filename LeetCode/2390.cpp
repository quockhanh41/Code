#include <iostream>
#include <stack>
#include <string>
using namespace std;
string removeStars(string s)
{
    int n = s.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
            j--;
        else
            s[j++] = s[i];
    }
    string res = "";
    for (int i = 0; i < j; i++)
    {
        res += s[i];
    }
    return res;
}
int main()
{
    cout << removeStars("leet**cod*e");
}