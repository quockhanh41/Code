#include <iostream>
using namespace std;
int strStr(string haystack, string needle)
{
    return haystack.find(needle);
}
int main()
{

    cout << strStr("a", "a");
}