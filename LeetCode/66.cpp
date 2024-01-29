#include <iostream>
#include <vector>
using namespace std;
vector<int> plusOne(vector<int> &digits)
{
    string num = "0";
    for (auto x : digits)
        num += x + '0';
    int mem = 1;
    int i = num.size() - 1;
    while (mem > 0)
    {
        num[i] = num[i] + mem - '0';
        if (num[i] > 9)
            mem = 1;
        else
            mem = 0;
        num[i] = num[i] % 10 + '0';
        i--;
    }
    vector<int> res;
    i = 0;
    if (num[0] == '0')
        i++;
    for (; i < num.size(); i++)
        res.push_back(num[i] - '0');
    return res;
}
int main()
{
    vector<int> a = {1, 9, 9, 9, 9, 9};
    for (auto x : plusOne(a))
        cout << x << " ";
}