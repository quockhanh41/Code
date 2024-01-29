#include <iostream>
using namespace std;
bool checkAlmostEquivalent(string word1, string word2)
{
    int n = word1.size();
    int cnt1[256] = {0};
    int cnt2[256] = {0};
    for (int i = 0; i < n; i++)
    {
        cnt1[word1[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        cnt2[word2[i]]++;
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (abs(cnt1[i] - cnt2[i]) > 3)
            return false;
    }
    return true;
}
int main()
{
    cout << checkAlmostEquivalent("abcdeef", "abaaacc");
}