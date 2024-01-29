#include <iostream>
#include <vector>
using namespace std;
vector<double> sampleStats(vector<int> &count)
{
    double most = 0;
    vector<double> res;
    double min = INT_MAX;
    double max = INT_MIN;
    double sum = 0.0;
    vector<int> a;
    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] > 0)
        {
            if (i < min)
                min = i;
            if (i > max)
                max = i;
            sum += i * count[i];
        }
        if (count[i] > count[most])
            most = i;
        for (int j = 0; j < count[i]; j++)
        {
            a.push_back(i);
        }
    }
    res.push_back(min);
    res.push_back(max);
    res.push_back(sum / a.size());

    if (a.size() % 2 == 0)
    {
        int i = a.size() / 2 - 1;
        res.push_back((a[i] + a[i + 1]) / 2.0);
    }
    else
        res.push_back(a[a.size() / 2 + 1]);
    res.push_back(most);

    return res;
}
int main()
{
    vector<int> a = {0, 1, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (auto x : sampleStats(a))
        cout << x << " ";
}