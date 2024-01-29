#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSessions(vector<int> &tasks, int sessionTime)
{
    sort(tasks.begin(), tasks.end());
    int n = tasks.size();
    int sum = 0;
    int count = 1;
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        cout << tasks[l] << " " << tasks[r] << " " << count << endl;
        if (sum + tasks[r] <= sessionTime)
        {
            sum += tasks[r];
            r--;
            l++;
        }
        else if (sum + tasks[l] <= sessionTime)
        {
            sum += tasks[l];
            l++;
            r--;
        }
        else
        {
            count++;
            sum = 0;
            r--;
            l++;
        }
    }
    return count;
}
int main()
{
    vector<int> a = {4, 6, 8, 8, 9};
    cout << minSessions(a, 14);
}