#include <iostream>
using namespace std;
int romanToInt(string s)
{
    int sum = 0;
    int k = s.size();
    int i = 0;
    while (k--)
    {
        if (s[i] == 'M')
            sum += 1000;

        else if (s[i] == 'D')
            sum += 500;

        else if (s[i] == 'C')
        {
            if (s[i + 1] == 'M')
            {
                sum += 900;
                i++;
                k--;
            }
            else if (s[i + 1] == 'D')
            {
                sum += 400;
                i++;
                k--;
            }
            else
                sum += 100;
        }

        else if (s[i] == 'L')
            sum += 50;

        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'L')
            {
                sum += 40;
                i++;
                k--;
            }
            else if (s[i + 1] == 'C')
            {
                sum += 90;
                i++;
                k--;
            }
            else
                sum += 10;
        }

        else if (s[i] == 'V')
            sum += 5;

        else if (s[i] == 'I')
        {
            if (s[i + 1] == 'V')
            {
                sum += 4;
                i++;
                k--;
            }
            else if (s[i + 1] == 'X')
            {
                sum += 9;
                i++;
                k--;
            }
            else
                sum += 1;
        }
        i++;
    }
    return sum;
}
int main()
{
    cout << romanToInt("IV");
}