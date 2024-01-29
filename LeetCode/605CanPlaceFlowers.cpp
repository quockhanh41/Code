#include <iostream>
#include <vector>
using namespace std;
bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    if (n == 0)
        return 1;
    vector<int> a;
    a.push_back(0);
    for (auto x : flowerbed)
        a.push_back(x);
    a.push_back(0);
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (a[i - 1] != 1 && a[i + 1] != 1)
        {
            if (a[i - 1] != 1 && a[i + 1] != 1 && a[i] == 1)
                continue;
            cout << i - 1 << " " << i + 1 << endl;
            a[i] = 1;
            n--;
            if (n == 0)
                return 1;
        }
    }

    return 0;
}

// bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         int i = 0;
        
//         while(i < flowerbed.size() && n>0){
//             if(flowerbed[i] == 1){
//                 i += 2;
//             }
//             else if(i+1 == flowerbed.size() || flowerbed[i+1] != 1){
//                 n--;
//                 i += 2;
//             }
//             else
//                 i++;
//         }
//         return n==0;
//     }
int main()
{

    vector<int> a = {1, 0, 0, 0, 1, 0, 0};
    cout << canPlaceFlowers(a, 2);
}