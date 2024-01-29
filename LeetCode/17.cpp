#include <iostream>
#include <vector>
using namespace std;
vector<string> letterCombinations(string digits)
{
    int k = 'a';
    char a[9][3];
    for (int i = 2; i < 7; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = k++;
        }
    }
    a[7][] = {'p', 'q', 'r', 's'};
}
int main()
{
    letterCombinations("23");
}