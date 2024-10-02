#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> finalPrices(vector<int> &prices)
{
    stack<int> s;
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() > prices[i])
            s.pop();
        int temp = prices[i];
        if (!s.empty())
        {
            prices[i] -= s.top();
        }
        s.push(temp);
    }
    return prices;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}