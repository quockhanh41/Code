#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool checkIfExist(vector<int> &arr)
{
    int cnt0 = 0;
    map<int, bool> visited;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            cnt0++;
            if (cnt0 == 2)
                return 1;
        }
        else
        {
            visited[arr[i]] = 1;
            if (arr[i] & 1)
            {
                if (visited[2 * arr[i]])
                    return 1;
            }
            else if ((visited[2 * arr[i]] || visited[arr[i] / 2]))
                return 1;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}