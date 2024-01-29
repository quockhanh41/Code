#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
string robotWithString(string s)
{
    string res;
    stack<char> t;
    char target = 'a';
    while (!s.empty() && !t.empty())
    {
        int index = s.find(target);
        if (index >= s.size() || index < 0)
        {
            target++;
        }
        else
        {
            for (int i = 0; i <= index; i++)
                t.push(s[i]);
            s = s.substr(index + 1, s.size() - (index + 1));
            res += t.top();
            t.pop();
            if (!t.empty())
            {
                if (char(target + 1) == t.top())
                {
                    res += t.top();
                    t.pop();
                }
            }
        }
    }

    while (!t.empty())
    {
        res += t.top();
        t.pop();
    }
    return res;
}
int main()
{
    cout << robotWithString("fgbdaced");
}
