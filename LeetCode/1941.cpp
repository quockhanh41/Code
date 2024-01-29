#include <iostream>
using namespace std;
bool areOccurrencesEqual(string s)
{
    int cnt[256] = {};
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i]]++;
    }
    int n = cnt[s[0]];
    for (int i = 0; i < s.size(); i++)
    {
        if (cnt[s[i]] != n)
            return false;
    }
    return true;
}
char repeatedCharacter(string s)
{
    int cnt[256] = {};
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i]]++;
        if (cnt[s[i]] == 2)
            return s[i];
    }
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
            return s[i];
    }
    return 1;
}
int main()
{
    cout << repeatedCharacter("izspyzhxvhmvsqekrauyugcbepvifvgnpthxrqunslwvgfdnzfzdxockaoomqybnsfzewkcspwpepvbyohccnoivagjhzplnkcvr");
}