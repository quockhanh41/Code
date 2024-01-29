#include <iostream>
#include <vector>
#include <string>
using namespace std;
string reorderSpaces(string text)
{
    string res = "";
    int n = text.size();
    int totalSpace = 0;
    int word = 0;
    if (text[n - 1] != ' ')
        word++;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == ' ')
            totalSpace++;
        if (text[i] != ' ' && text[i + 1] == ' ')
            word++;
    }
    int space = totalSpace / (word -1);
    int extraSpace = totalSpace - sapce* (word-1);

    while (text.back() == ' ')
        text.erase(text.size() - 1, 1);
    for (int i = 0; i < n; i++)
    {
        if (text[i] != ' ')
            res += text[i];
        else if (text[i] == ' ' && text[i - 1] != ' ' && i != 0)
        {
            for (int i = 0; i < space; i++)
                res += " ";
        }
    }
    for (int i = 0; i < extraSpace; i++)
        res += " ";
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << reorderSpaces("  this   is  a sentence ");
    return 0;
}