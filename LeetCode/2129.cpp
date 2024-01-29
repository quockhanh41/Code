#include <iostream>
using namespace std;
string capitalizeTitle(string title)
{
    title = " " + title;
    int n = title.size();
    for (int i = 1; i < n; i++)
    {
        if (title[i - 1] == ' ')
            title[i] = toupper(title[i]);
        else if (title[i] != ' ')
            title[i] = tolower(title[i]);
    }
    title = title + " ";
    int k = 0;
    while (title.find(" ", k + 1) <= n + 1)
    {
        // cout << title.find(" ", k + 1) << " " << k << endl;
        if (title.find(" ", k + 1) - k <= 3)
            title[k + 1] = tolower(title[k + 1]);
        k = title.find(" ", k + 1);
    }
    title.erase(0, 1);
    title.erase(title.size(), 1);
    return title;
}
int main()
{
    string s = "L hV";
    cout << capitalizeTitle(s);
}