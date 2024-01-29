#include <iostream>
using namespace std;
int distMoney(int money, int children)
{
    if (money < children)
        return -1;
    if (money == 8 * children)
        return children;
    for (int i = children; i > 0; i--)
    {
        if (money - i * 8 == 4 && children - i == 1)
            return i - 1;
        if (money - i * 8 >= children - i && children - i > 0)
            return i;
    }
    return 0;
}
int main()
{
    cout << distMoney(17, 2);
}