#include <iostream>
using namespace std;
int balancedString(string s)
{
    int res = 0;
    int cnt[256] = {0};
    int n = s.size();
    int b = n / 4;
    for (int i = 0; i < n; i++)
    {
        cnt[s[i]]++;
    }
    for (int i = 69; i <= 87; i++)
    {
        cout << (char)i << " " << cnt[i]<<endl;
        if (cnt[i] > b)
            res += cnt[i] - b;
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << balancedString(s);
}