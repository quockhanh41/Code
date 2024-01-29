#include <iostream>
#include <map>
#include <vector>
using namespace std;
int countWords(vector<string> &words1, vector<string> &words2)
{
    int res = 0;
    map<string, int> cnt1;
    map<string, int> cnt2;
    for (auto x : words1)
        cnt1[x]++;
    for (auto x : words2)
        cnt2[x]++;
    for (auto x : words1)
        if (cnt1[x] == 1 && cnt2[x] == 1)
            res++;
    return res;
}

