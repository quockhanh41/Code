#include <iostream>
#include <vector>
#include <string>

using namespace std;
int numOfStrings(vector<string> &patterns, string word)
{
    int count = 0;
    int p = patterns.size();
    int n = word.size();
    for (int i = 0; i < p; i++)
    {
        if (word.find(patterns[i]) < n)
            count++;
    }
    return count;
}
int main()
{
    vector<string> a = {"a", "b", "c"};
    string word = "aaaaabbbbb";

    cout << numOfStrings(a, word);
}