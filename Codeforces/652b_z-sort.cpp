#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    // Swap adjacent elements starting from index 1
    for (int i = 1; i + 1 < n; i += 2)
    {
        swap(v[i], v[i + 1]);
    }

    // Print the result
    for (int i = 0; i < n; i++)
    {
        cout << v[i];
    }
    
    return 0;
}