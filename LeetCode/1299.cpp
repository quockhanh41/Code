#include <iostream>
#include <vector>
using namespace std;
vector<int> replaceElements(vector<int> &arr)
{
    int temp;
    int n = arr.size();
    int flag = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > flag)
        {
            temp = arr[i];
            arr[i] = flag;
            flag = temp;
        }
        else
            arr[i] = flag;
    }
    arr[n - 1] = -1;
    return arr;
}
int main()
{
    vector<int> a = {57010,40840,69871,14425,70605};
    for (auto x : replaceElements(a))
        cout << x << " ";
    return 0;
}