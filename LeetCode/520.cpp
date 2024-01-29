#include <iostream>
#include <string>
using namespace std;
bool detectCapitalUse(string word)
{
    if (word == "USA")
        return true;
    int up = 0;
    for (int i = 0; i < word.size(); i++)
        if (word[i] >= 'A' && word[i] <= 'Z')
            up++;
    if ((word[0] >= 'A' && word[0] <= 'Z' && (up == 1 || up == word.size())) || up == 0)
        return true;
    return false;
}
int main()
{
    cout << detectCapitalUse("G");
}