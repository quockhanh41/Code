#include <iostream>
using namespace std;

int *mergeArrays(int *a, int m, int *b, int n)
{
    int *x = new int[m + n]; // Mảng kết quả
    int i = 0, j = n - 1, k = 0;
    while (k < m + n)
    {
        if (i >= m)
        {
            while (j != -1)
                x[k++] = b[j--];
            break;
        }
        if (j < 0)
        {
            while (i < m)
                x[k++] = a[i++];
            break;
        }
        if (a[i] > b[j] && i < m)
            x[k++] = a[i++];
        else if (a[i] <= b[j] && j >= 0)
            x[k++] = b[j--];
    }
    return x;
}

int main()
{
    int a[] = {-1};
    int m = sizeof(a) / sizeof(a[0]);
    int b[] = {55, 56, 57, 57};
    int n = sizeof(b) / sizeof(b[0]);

    int *x = mergeArrays(a, m, b, n);

    // In kết quả
    for (int i = 0; i < m + n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;

    delete[] x; // Giải phóng bộ nhớ đã cấp phát động

    return 0;
}
