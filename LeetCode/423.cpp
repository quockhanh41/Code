#include <iostream>
#include <vector>
#include <string>
using namespace std;
int countNumber(int cnt[], string s)
{
    int res = INT_MAX;
    int demand[123] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        demand[s[i]]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        res = min(res, cnt[s[i]] / demand[s[i]]);
    }
    if (res == 0)
        return 0;
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i]] -= demand[s[i]] * res;
    }

    // for (int i = 0; i < s.size(); i++)
    // {
    //     cout << cnt[s[i]] << " " << demand[s[i]] << endl;
    // }
    return res;
}
string originalDigits(string s)
{
    string res = "";
    int cnt[123] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i]]++;
    }
    string a[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = 0; i < 10; i++)
    {
        int n = countNumber(cnt, a[i]);
        cout << i << n << endl;
        for (int j = 0; j < n; j++)
        {
            res += to_string(i);
        }
    }
    return res;
}
int main()
{
    cout << originalDigits("zeroonetwothreefourfivesixseveneightnine");

    return 0;
}