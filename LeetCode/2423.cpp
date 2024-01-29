#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool equalFrequency(string word)
{
    int cot = 0;
    int cnt[256] = {0};
    vector<int> ans;
    for (int i = 0; i < word.size(); i++)
        cnt[word[i]]++;
    for (int i = 0; i < word.size(); i++)
        if (cnt[word[i]])
        {
            ans.push_back(cnt[word[i]]);
        }

    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << equalFrequency("abcc");
    return 0;
}