#include <iostream>
#include <map>
#include <vector>
using namespace std;
string getHint(string secret, string guess)
{
    map<char, bool> khac;
    map<char, bool> trung;
    string res = "";
    int a = 0;
    int b = 0;
    int n = secret.size();
    for (int i = 0; i < n; i++)
    {
        if (secret.find(guess[i]) <= n && guess[i] != secret[i])
            khac[guess[i]] = 1;
        if (secret[i] == guess[i])
        {
            a++;
            trung[secret[i]] = 1;
        }
    }
    for (int i = 0; i < khac.size(); i++)
    {
        if (khac[guess[i]] ==1  && trung[guess[i]] == 0)
            b++;
    }

    res += (a + '0');
    res += "A";
    res += (b + '0');
    res += "B";
    return res;
}
int main()
{
    string a = "1122";
    string b = "2211";
    cout << getHint(a, b);
}