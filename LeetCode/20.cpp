#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    int n = s.size();
    stack<char> t;
    for (int i = 0; i < n; i++)
    {
        if (t.empty() && (s[i] == '}' || s[i] == ')' || s[i] == ']'))
            return false;
        else if ((s[i] == '}' && t.top() == '{') || (s[i] == ')' && t.top() == '(') || (s[i] == ']' && t.top() == '['))
            t.pop();
        else
            t.push(s[i]);
    }
    return t.empty();
}
int main()
{
    cout << isValid("(){}}{");
}