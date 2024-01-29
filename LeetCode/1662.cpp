#include <iostream>
#include <vector>
using namespace std;
bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
{
    string s1, s2;
    s1 = "";
    s2 = "";
    for (auto x : word1)
        s1 += x;
    for (auto x : word2)
        s2 += x;
    return s1 == s2;
}
int main()
{
    vector<string> s1 = {"ab", "c"};
    vector<string> s2 = {"a", "bcd"};
    cout << arrayStringsAreEqual(s1, s2);
    return 0;
}