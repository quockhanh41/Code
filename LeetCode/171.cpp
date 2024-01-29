#include <iostream>
#include <cmath>
using namespace std;

int titleToNumber(string columnTitle)
{
    char x = 'A';
    int letter[256];
    for (int i = 1; i <= 26; i++)
        letter[x++] = i;
    int n = columnTitle.size();
    int res = 0;
    int k = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        res += letter[columnTitle[k++]] * pow(26, i);
    }
    return res;
}
int main()
{
    cout << titleToNumber("AAA");
}