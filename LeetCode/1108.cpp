#include <iostream>
#include <vector>
using namespace std;
string defangIPaddr(string address)
{
    string res = "";
    for (int i = 0; i < address.size(); i++)
    {
        if (address[i] != '.')
            res += address[i];
        else
            res += "[.]";
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}