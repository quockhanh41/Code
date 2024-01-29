#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;
string reverseWords(string s)
{

    s = s + " ";
    int j = 0;
    int right;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            right = i - 1;
            while (j < right)
            {
                swap(s[j++], s[right--]);
            }
            j = i + 1;
        }
    }
    s.erase(s.size()-1);
    return s ;
}

int main()
{
    string s = "Let's take LeetCode contest";
    cout << reverseWords(s);
}