#include <iostream>
#include <vector>
using namespace std;
int numSquares(int n)
{
    int res = 0;
    if (n < 1)
        return 0;
    vector<int> square;
    square.push_back(1);
    bool isQuare[1000] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (!isQuare[i])
        {
            int j = i;
            while (j * j <= n)
            {
                isQuare[j * j] = 1;
                j = j * j;
            }
        }
        else
            square.push_back(i);
    }
}
int main()
{
    numSquares(12);
}