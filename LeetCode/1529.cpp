#include <iostream>
using namespace std;
int largestposv3(int a[], int *n, int *index)
{
    if (n == a)
        return index - a;
    if (*n > *index)
        index = n;
    return largestposv3(a, n - 1, index);
}
int main()
{
    int a[] = {5, 6, 3, 4, 5, 3, 2};
    int n = sizeof(a) / sizeof(int);
    cout << largestposv3(a, a + n - 1, a + n);
}