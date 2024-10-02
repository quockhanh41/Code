#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
string longestPalindrome(string s)
{
    int n = s.size(), start = 0, maxlen = 0;
    int left = 0, right = 0;
    if (n < 2)
        return s;
    for (int i = 0; i < n - 1; i++)
    {
        left = i - 1, right = i + 1;
        // while (right < n && s[right] == s[right + 1])
        //     ++right;
        // i = right + 1;
        // cout << i << " ";
        while (left >= 0 && right < n && s[left] == s[right])
            --left, ++right;
        if (maxlen < right - left - 1)
            maxlen = right - left - 1, start = left + 1;
    }
    return s.substr(start, maxlen);
}
int main()
{
    cout << longestPalindrome("cbbbd");
}