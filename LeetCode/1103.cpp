#include <iostream>
#include <vector>
using namespace std;
vector<int> distributeCandies(int candies, int num_people)
{
    vector<int> res(num_people);
    int index = 0;
    int candy = 1;
    while (candies > 0)
    {
        if (candy <= candies)
            res[index] += candy;
        else
        {
            res[index] += candies;
        }
        candies -= candy;
        candy++;
        if (index == num_people - 1)
            index = 0;
        else
            index++;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (auto x : distributeCandies(7, 4))
        cout << x << " ";
    return 0;
}