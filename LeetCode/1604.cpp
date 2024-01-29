#include <iostream>
#include <vector>
#include <list>
using namespace std;
int time(string s)
{
    int h;
    h = s[0] - '0';
    h = h * 10 + s[1] - '0';
    int m;
    m = s[3] - '0';
    m = m * 10 + s[4] - '0';
    return h * 60 + m;
}
vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
{
    string name = keyName[0];
    int cnt = 1;
    int t = time(keyTime[0]);
    list<string> res;
    int n = keyName.size();
    for (int i = 1; i < n; i++)
    {
        if (name == keyName[i] && time(keyTime[i]) <= 24 * 60)
        {
            cnt++;
            if (time(keyTime[i]) - t <= 60 && cnt == 3)
                res.push_back(keyName[i]);
        }
        else
        {
            name = keyName[i];
            t = time(keyTime[i]);
            cnt = 1;
        }
    }
    vector<string> ans(res.begin(), res.end());
    return ans;
}
int main()
{
    vector<string> a = {"john","john","john"};
    vector<string> b = {"23:58","23:59","00:01"};
    for (auto x : alertNames(a, b))
        cout << x << " ";
    return 0;
}