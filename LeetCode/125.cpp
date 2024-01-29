#include <iostream>
using namespace std;
bool isPalindrome(string s)
{
    int l = 0;
    int r = s.size() - 1;
    while (l <= r)
    {
        while (s[l] < '0' || s[l] > 'z' || (s[l] > '9' && s[l] < 'A') || (s[l] > 'Z' && s[l] < 'a'))
        {
            l++;
            if (l >= s.size())
                return 1; 
        }
        while (s[r] < '0' || s[r] > 'z' || (s[r] > '9' && s[r] < 'A') || (s[r] > 'Z' && s[r] < 'a'))
        {
            r--;
            if (r < 0)
                return 1;
        }
        if (s[l] >= 'A' && s[l] <= 'z' && s[l] >= 'A' && s[l] <= 'z')
        {
            if (tolower(s[l]) != tolower(s[r]))
                return 0;
        }
        else if (s[l] != s[r])
            return 0;
        l++;
        r--;
    }
    return 1;
}
int main()
{
    cout << isPalindrome("ab_a");
}