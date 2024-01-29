#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool closeStrings(string word1, string word2)
{
    if (word1.size() != word2.size())
        return false;
    int cnt1[256] = {};
    int cnt2[256] = {};
    for (int i = 0; i < word1.size(); i++)
    {
        cnt1[word1[i]]++;
    }
    for (int i = 0; i < word2.size(); i++)
    {
        cnt2[word2[i]]++;
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (cnt1[i] != 0 && cnt2[i] == 0 || cnt2[i] != 0 && cnt1[i] == 0)
            return false;
    }
    vector<int> a;
    vector<int> b;
    int cntchr1 = 0;
    int cntchr2 = 0;
    for (int i = 'a'; i <= 'z'; i++)
    {

        a.push_back(cnt1[i]);
        b.push_back(cnt2[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b && cntchr1 == cntchr2;
}
int main()
{
    cout << closeStrings("uau", "ssx");
}