#include <iostream>
#include <map>
using namespace std;
string decodeMessage(string key, string message)
{
    map<char, char> f;
    bool check[256] = {0};
    int n = key.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {

        if (check[key[i]] == 0 && key[i] != ' ')
        {
            f[key[i]] = 'a' + j++;
            check[key[i]] = 1;
        }
    }

    n = message.size();
    for (int i = 0; i < n; i++)
    {
        if (message[i] != ' ')
        {
            message[i] = f[message[i]];
        }
    }

    return message;
}
int main()
{
    string key = "thequickbrownfoxjumpsoverthelazydog", message = "vkbs bs t suepuv";
    cout << decodeMessage(key, message);
}