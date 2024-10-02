#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int res = 0;
    int chosing = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < chosing)
        {
            chosing = prices[i];
            continue;
        }
        res = max(res, prices[i] - chosing);
    }
    return res;
}

int main()
{
}