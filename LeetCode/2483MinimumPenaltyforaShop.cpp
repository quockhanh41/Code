#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int bestClosingTime(string customers)
{

    int count = 0;

    int n = customers.size();
    for (int i = 0; i < n; i++)
    {
        if (customers[i] == 'y')
            count++;
    }
    int min = count;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (customers[i] == 'N')
            count++;
        else
            count--;
        if (count < min)
        {
            min = count;
            k = i + 1;
        }
    }

    return k;
}
int main()  
{

    cout << bestClosingTime("YYYY");
    return 0;
}
