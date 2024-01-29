#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool checkInclusion(string s1, string s2)
{
    int count = 0;
    for (int i = 0; i < s2.size(); i++)
    {
        if (s1.find(s2[i]) <= s1.size())
            count++;
    }
    if (count == s1.size() || count == s2.size())
        return true;
    return false;
}
int main()
{
    string s1 = {"eidbaooo"};
    string s2 = {"ab"};
    cout << checkInclusion(s1, s2);
}