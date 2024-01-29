#include <iostream>
using namespace std;
int minTimeToType(string word)
{

    int n = word.size();
    int count = n;
    word = 'a' + word;
    for (int i = 0; i < word.size() - 1; i++)
    {
        if (abs(word[i + 1] - word[i]) > 13)
            count += 26 - abs(word[i + 1] - word[i]);
        else
            count += abs(word[i + 1] - word[i]);
    }
    return count;
}
int main()
{
    cout << minTimeToType("zjpc");
}