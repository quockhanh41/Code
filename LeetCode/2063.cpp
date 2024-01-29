#include <iostream>
#include <cstring>
#include <string>
using namespace std;
bool find(char x)
{
    if (x == 'u' || x == 'e' || x == 'o' || x == 'a' || x == 'i')
        return 1;
    return 0;
}
long long countVowels(string word)
{
    long long res = 0;
    int n = word.size();
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = new int[n + 1];
    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (k == 1)
                dp[i][j] = find(word[i]);
            else
                dp[i][j] = dp[i][j - 1] + find(word[j]);
            res += dp[i][j];
        }
    }
    delete[] dp;
    return res;
}
int main()
{
    string s = "abcde";
    cout << countVowels(s);
}
